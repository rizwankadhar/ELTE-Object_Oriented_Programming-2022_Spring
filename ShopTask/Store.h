#ifndef STORE_H
#define STORE_H
#include "Department.h"

class Store
{
    public:
        Store(const std::string &foodsFile, const std::string &techFile);
        ~Store();

        Department* foods;
        Department* technical;

};

#endif // STORE_H
