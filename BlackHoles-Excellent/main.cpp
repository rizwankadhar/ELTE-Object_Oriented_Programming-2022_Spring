#include "inFile.h"

using namespace std;

bool emptyFile(const string &fileName);

int main()
{
    cout<< "----- Blackholes closer than 2700 light years -----\n\n";
    string fileName = "input.txt";
    /**cout << "Name of the input file: ";
    cin >> fileName;*/
    try
    {
        if (emptyFile(fileName))
        {
            cout << "Empty file!\n";
            return 1;
        }
        cout << "Average weight of the close blackholes:\n";
        inFile t(fileName);
        for( t.first() ; !t.end() ; t.next())
        {
            if (t.current().allClose)
            {
                cout << "\t" << t.current().name << ", average weight: " << t.current().avgOfWeights << endl;
            }
        }
    }
    catch (inFile::Error exp)
    {
        cout << "Wrong file name!\n";
        return 2;
    }
    return 0;
}

bool emptyFile(const string &fileName)///To handle the empty file case
{
    inFile t(fileName);
    t.first();
    t.next();
    ///On calling the next operation, if it reached the end,
    ///then its an empty file
    if (t.end())
    {
        return true;
    }
    return false;
}

