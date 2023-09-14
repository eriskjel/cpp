//
// Created by eriks on 09/09/2023.
//

#include "Commodity.h"
#include <iostream>
#include <string>

using namespace std;

int main() {
    const double quantity = 2.5;
    Commodity commodity("Norvegia", 123, 73.50);

    cout << "Varenavn: " << commodity.getName() << ", varenr: " << commodity.getId()
         << " Pris pr enhet: " << commodity.getPrice() << endl;

    cout << "Kilopris: " << commodity.getPrice() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.getPrice(quantity)
         << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.getPriceWithSalesTax(quantity)
         << " med moms" << endl;

    commodity.setPrice(79.60);
    cout << "Ny kilopris: " << commodity.getPrice() << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.getPrice(quantity)
         << " uten moms" << endl;
    cout << "Prisen for " << quantity << " kg er " << commodity.getPriceWithSalesTax(quantity)
         << " med moms" << endl;
}
