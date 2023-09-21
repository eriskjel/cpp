#include <boost/asio.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace std;
using namespace boost::asio::ip;

class WebServer {
private:
    class Connection {
    public:
        tcp::socket socket;
        Connection(boost::asio::io_service &io_service) : socket(io_service) {}
    };

    boost::asio::io_service io_service;

    tcp::endpoint endpoint;
    tcp::acceptor acceptor;

    void handle_request(shared_ptr<Connection> connection) {
        auto read_buffer = make_shared<boost::asio::streambuf>();
        async_read_until(connection->socket, *read_buffer, "\r\n\r\n",
                         [this, connection, read_buffer](const boost::system::error_code &ec, size_t) {
                             if (!ec) {
                                 istream request_stream(read_buffer.get());
                                 string http_method, http_path, http_version;
                                 
                                 // Parse HTTP request line
                                 request_stream >> http_method >> http_path >> http_version;
                                 
                                 auto response = make_shared<boost::asio::streambuf>();
                                 ostream response_stream(response.get());
                                 
                                 string body;
    
                                 if (http_method == "GET" && http_path == "/") {
                                     body = "Dette er hovedsiden";
                                 } else if (http_method == "GET" && http_path == "/en_side") {
                                     body = "Dette er en side";
                                 } else {
                                     body = "Not Found";
                                 }
    
                                 response_stream << "HTTP/1.1 ";
                                 if (body == "Not Found") {
                                     response_stream << "404 Not Found";
                                 } else {
                                     response_stream << "200 OK";
                                 }
                                 response_stream << "\r\nContent-Length: " << body.length() << "\r\n\r\n" << body;
    
                                 async_write(connection->socket, *response,
                                             [this, connection, response](const boost::system::error_code &ec, size_t) {
                                                 if (!ec)
                                                     handle_request(connection);
                                             });
                             }
                         });
    }
    
    

    void accept() {
        auto connection = make_shared<Connection>(io_service);
        acceptor.async_accept(connection->socket, [this, connection](const boost::system::error_code &ec) {
            accept();
            if (!ec) {
                handle_request(connection);
            }
        });
    }

public:
    WebServer() : endpoint(tcp::v4(), 8080), acceptor(io_service, endpoint) {}

    void start() {
        accept();
        io_service.run();
    }
};

int main() {
    WebServer web_server;

    cout << "Starting web server on http://localhost:8080" << endl;

    web_server.start();
}
