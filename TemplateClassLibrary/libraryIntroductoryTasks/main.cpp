#include <iostream>
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/counting.hpp"
#include "library/linsearch.hpp"
#include <fstream>

/*
Sum all the numbers in a given file using template class library(even, odd)
*/

using namespace std;


class mySum : public Summation<int>
{
    int func(const int& e) const override  { return e;}
    int neutral() const override { return 0; }
    int add( const int& a, const int& b) const { return a + b; }
    bool cond(const int& e) const override { return e % 2 == 1; }
};

class myCount : public Counting<int>
{

};

class mySearch : public LinSearch<int>
{
    bool cond(const int& e) const override {  return e % 2 == 0 && e > 6;}
};


class assortment : public Summation<int, ostream>
{
public:
    assortment(ostream *o) : Summation<int, ostream>::Summation(o) {}

protected:
    std::string func(const int& e) const override { return to_string(e) + " ";}
    bool cond(const int& e) const override { return e % 2 == 0; }
};



int main()
{
    try {

        ///mySum pr;
        ///myCount pr;
        ///mySearch pr;
        ofstream f("output.txt");
        assortment pr(&f);
        SeqInFileEnumerator<int> enor("input.txt");

        pr.addEnumerator(&enor);

        pr.run();
//        if (pr.found())
//        {
//            cout << pr.elem() <<endl;
//        }
        ///cout << "Count is :" << pr.result() <<endl;
    }catch (SeqInFileEnumerator<int>::Exceptions e)
    {
        cout <<" File not found!";
    }

    return 0;
}
