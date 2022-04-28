#ifndef DEPARTMENT_H
#define DEPARTMENT_H
#include <vector>
#include <fstream>
#include "Product.h"

class Department
{
    public:
        Department(const std::string &filename);
        void takeOut(Product *p);
        ~Department();

        std::vector<Product *> stock;
};

#endif // DEPARTMENT_H
