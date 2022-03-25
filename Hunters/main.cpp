#include <iostream>
#include "InFile.h"


/**
In a sequential input file, hunt trophies are stored: hunter name, species, weight.
One hunter's data can be in more than one lines. File is ordered by hunter names.
 a. How many hunters have shot rabbit(In any of their hunts)?
 b. On average, how many preys have the hunters shot? In case of empty file, the average is zero!
*/

///I combined both the tasks

using namespace std;


int main()
{
    string filename = "input.txt";
    try {
        InFile t(filename);

        int rabbitHuntersCnt =0;
        int allHuntersCnt = 0;
        int sumOfAnimalsHunted = 0;
        double avgOfAnimalsHunted;

        for (t.first(); !t.end(); t.next())
        {
            if (t.current().shotRabbit) rabbitHuntersCnt++;
            allHuntersCnt++;
            sumOfAnimalsHunted += t.current().cntHunts;
        }
        if (allHuntersCnt > 0)
        {
            avgOfAnimalsHunted = double(sumOfAnimalsHunted) / allHuntersCnt;
        }
        else
        {
            avgOfAnimalsHunted = 0;
        }

        cout << "Number of Hunters who shot rabbit is: " << rabbitHuntersCnt<<endl;
        cout << "\n\nOn average, one Hunter shot " << avgOfAnimalsHunted << " animals\n";


    }catch (InFile::ERRORS err)
    {
        cerr <<"File does not exist!\n";
    }


    return 0;

}
