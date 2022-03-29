#include <iostream>
#include "InFile.h"

///Which days had more, than 10 flights? You have to create a class with methods
///first(), next(), current(), and end() for enumerating the number of flights for each day.
///Other public methods cannot be created for this class.

///In the sample file the output is empty.

using namespace std;

int main()
{
    try {
        string filename = "inp.txt";
//        cin >> filename;
        InFile t(filename);
        t.first();
        if (t.end())
        {
            cerr <<"Empty file!";
        }else
        {
            cout << "Days with more than 10 flights are: \n";
            int cnt = 0;
        while (!t.end())
        {
            if (t.current().cntFlights >= 1)
            {
                cnt++;
                cout << "\t"<< t.current().date << " "<< t.current().cntFlights <<endl;
            }
            t.next();
        }
        if (cnt == 0)
        {
                cout << "There was no day with more than 10 flights!\n";
        }


        }

    }catch (InFile::Errors err)
    {
        cerr << "Invalid File!\n";
    }
    return 0;
}
