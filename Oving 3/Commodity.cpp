//
// Created by eriks on 09/09/2023.
//

#include "Commodity.h"
#include <string>
#include <utility>

Commodity::Commodity(std::string name_, int id_, double price_) : name(std::move(name_)), id(id_), price(price_)
{}

std::string Commodity::getName() const {
    return name;
}

int Commodity::getId() const {
    return id;
}

double Commodity::getPrice(double quantity) const {
    return price * quantity;
}

double Commodity::getPriceWithSalesTax(double quantity) const {
    return getPrice(quantity) * (1 + tax);
}

void Commodity::setPrice(double price_) {
    price = price_;
}

