#include <iostream>
#include <fstream>

//
///After the first half-empty flight (NoP/PC<=0.5) how many flights were there, where the plane was big (PC>=150)?
/// You have to define a method for
/// reading from the file and you have to create an algorithm which
/// is based on the general algorithm of the algorithmic patterns.
using namespace std;

enum Status { norm , abnorm };


struct Flight{
    string date;
    string id;
    int PC;
    int NoP;

    friend istream &operator>>(istream &is, Flight &f)
    {
        is >> f.date >> f.id >> f.PC >> f.NoP;
        return is;
    }

};


void read(Status &st, Flight &e , ifstream &f); ///st, e, f: read
int bigAfterEmpty(ifstream &f);

int main()
{
    string filename = "inp.txt";
    ifstream f;
    f.open(filename.c_str());
    if (f.fail())
    {
        cout << "Invalid file\n";
    }
    else {
        int result = bigAfterEmpty(f);
        if (result == -1)
        {
            cout <<"There is no flight in the file!\n";
        }
        else
        {
            cout << "There are(is) " << result <<" flight(s) where plane was big.\n";
        }

    }

    return 0;
}

void read(Status &st, Flight &e , ifstream &f)
{
    f >> e;
    if (f.fail())
    {
        st = abnorm;
    }
    else
    {
        st = norm;
    }
}

int bigAfterEmpty(ifstream &f)
{
    Status st;///st, e, f:read
    Flight e;
    read(st, e ,f);
    if (st == abnorm )
    {
        return -1;
    }

    while (st == norm && (double (e.NoP) / e.PC) > 0.5)
    {
        read(st, e, f);
    }

    int cnt = 0;
    read(st, e ,f);

    while (st == norm)
    {
        if (e.PC >= 150) cnt++;
        read(st, e, f);
    }
    return cnt;
}
