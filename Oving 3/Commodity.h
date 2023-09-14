//
// Created by eriks on 09/09/2023.
//

#ifndef OVING_3_COMMODITY_H
#define OVING_3_COMMODITY_H
#include <string>




const double tax = 0.25;

class Commodity {
public:
    Commodity(std::string name_, int id_, double price_);
    std::string getName() const;
    int getId() const;
    double getPrice(double quantity = 1) const;
    double getPriceWithSalesTax(double quantity) const;
    void setPrice(double price);
private:
    std::string name;
    int id;
    double price;
};


#endif //OVING_3_COMMODITY_H
