#include "Store.h"

Store::Store(const std::string &foodsFile, const std::string &techFile)
{
    foods = new Department(foodsFile);
    technical = new Department(techFile);
}

Store::~Store()
{
    delete foods;
    delete technical;
}
