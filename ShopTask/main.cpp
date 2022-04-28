#include <iostream>
#include "Customer.h"

using namespace std;

int main()
{
    Customer c("shoplist.txt");


    Store store("foods.txt", "technical.txt");

    cout << "The customer has bought: \n" << c.purchase(store);
    return 0;
}
