#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Store.h"

class Customer
{
    public:
        Customer(const std::string &filename);
        ~Customer();

        std::string purchase(Store &store);

    private:
        std::string name;
        std::vector<std::string> shoplist;

        std::vector<Product *> cart;

        bool linSearch(std::string pName, Department* dept, Product* &p);
        bool minSearch(std::string pName, Department* dept, Product* &p);
};

#endif // CUSTOMER_H
