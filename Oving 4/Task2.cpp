#include <gtkmm.h>

class Window : public Gtk::Window {
public:
    Gtk::Box box;
    Gtk::Entry entry;
    Gtk::Button button;
    Gtk::Label label;

    Window() : box(Gtk::Orientation::ORIENTATION_VERTICAL) {
        button.set_label("Click here");

        box.pack_start(entry); 
        box.pack_start(button);
        box.pack_start(label);

        add(box);
        show_all(); 

        entry.signal_changed().connect([this]() {
            label.set_text("Entry now contains: " + entry.get_text());
        });

        entry.signal_activate().connect([this]() {
            label.set_text("Entry activated");
        });

        button.signal_clicked().connect([this]() {
            label.set_text("Button clicked");
        });
    }
};

int main() {
    auto app = Gtk::Application::create();
    Window window;
    return app->run(window);
}
