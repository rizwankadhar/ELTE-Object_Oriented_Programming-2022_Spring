#include "inFile.h"

using namespace std;

bool emptyFile(const string &fileName);
bool solutionOfAccepted(const string &fileName,Blackhole &elem);

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
        Blackhole elem;
        if (solutionOfAccepted(fileName,elem))
        {
            cout << "Maximal weight of the close blackholes belongs to " << elem.name << " with " << elem.lastWeight << " billion tons.\n\n";
        }
        else
        {
            cout << "There was no close blackhole in the file.\n\n";
        }
    }
    catch (inFileMax::Error exp)
    {
        cout << "Wrong file name!\n";
        return 2;
    }
    return 0;
}

bool emptyFile(const string &fileName)///To handle the empty file case
{
    inFileMax t(fileName);
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


bool solutionOfAccepted(const string &fileName, Blackhole &elem)///Conditional Max Search
{
    inFileMax t(fileName);
    bool l = false;
    int max;
    for( t.first() ; !t.end() ; t.next())
    {
        if (l && t.current().close)
        {
            if (t.current().lastWeight > max)
            {
                max = t.current().lastWeight;
                elem = t.current();
            }
        }
        else if (!l && t.current().close)
        {
            l = true;
            max = t.current().lastWeight;
            elem = t.current();
        }
    }
    return l;
}
