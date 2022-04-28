#ifndef PRODUCT_H
#define PRODUCT_H
#include <iostream>

class Product
{
    public:
        Product(const std::string n, int p) : name(n), price(p) {}

        std::string getName() const { return name;}
        int getPrice() const { return price;}

        bool operator==(const Product* p)
        {
            return p->getName() == name && p->getPrice() == price;
        }


    private:
        std::string name;
        int price;
};

#endif // PRODUCT_H
