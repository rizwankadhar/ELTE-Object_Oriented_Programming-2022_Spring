#include <iostream>
#include "Gardener.h"
using namespace std;


int main()
{
    Garden* garden = new Garden(5);
    Gardener* gardener = new Gardener(garden);

    gardener->garden->plant(2, Potatoe::getInstance(), 3);
    gardener->garden->plant(3, Rose::getInstance(), 4);

    cout << "IDs of parcels, where vegies are ready to harvest:\n";

    vector<int> result = gardener->garden->canHarvest(7);

    for (int i : result)
    {
        cout << i << " ";
    }
	return 0;
}
//
//
//class Base {
//  public:
//    int x;
//  protected:
//    int y;
//  private:
//    int z;
//};
//
//class PublicDerived: public Base {
//  // x is public
//  // y is protected
//  // z is not accessible from PublicDerived
//};
//
//class ProtectedDerived: protected Base {
//  // x is protected
//  // y is protected
//  // z is not accessible from ProtectedDerived
//};
//
//class PrivateDerived: private Base {
//  // x is private
//  // y is private
//  // z is not accessible from PrivateDerived
//};
//
//class anotherClass : private PrivateDerived {
//  // x is public
//  // y is protected
//  // z is not accessible from PublicDerived
//};
