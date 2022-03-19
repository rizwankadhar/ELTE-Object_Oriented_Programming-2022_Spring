#include <iostream>

#include "infile.h"

using namespace std;

int main()
{
    cout << "--- Number of occurrences of numbers ---\n\n";
    bool fileError = true;
    do
    {
        try
        {
            cout << "File's name: ";
            string fileName; /// = "inp.txt";
            cin >> fileName;
            inFile t(fileName);

            for( t.first(); !t.end(); t.next() ){
                cout  << t.current() << endl;
            }
            fileError = false;
        }
        catch (inFile::Errors err)
        {
            cout << "File Opening unsuccessful!\n";
        }
    } while (fileError);

    return 0;
}
