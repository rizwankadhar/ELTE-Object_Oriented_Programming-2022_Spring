#include <iostream>
#include "library/summation.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/linsearch.hpp"
#include "library/maxsearch.hpp"
#include "library/counting.hpp"

using namespace std;

struct Game {
    string name;
    int rank;

    friend istream& operator>>(istream &is, Game &g)
    {
        is  >> g.name >> g.rank;
        return is;
    }
};
///NOT RECOMMENDED(Solution b.)
///So, we need three things from one line, whether the student participated in highjump, whether the
///best place student obtained was a silver medal and how many silvers student has obtained.
///If we want to find these three things separately by using three different Algorithmic patterns,
///then we use the commented out part.
/*
class highJumped : public LinSearch<Game>
{
    bool cond(const Game& e) const override { return e.name == "highjump"; }
};

class findBestRank : public MaxSearch<Game, int, Less<int>>
{
    int func(const Game& e) const override { return e.rank; }
};

class countSilvers : public Counting<Game>
{
    bool cond(const Game& e) const override { return e.rank == 2; }
};
*/

struct sumResult
{
    bool highJump;///LinSearch
    int bestRank;///MaxSearch
    int silverMedals;///Count

    sumResult() {}
    sumResult(bool b, int bR, int sM) : highJump(b), bestRank(bR), silverMedals(sM) {}
};
///RECOMMENDED:
///We have to get three things, so instead of using three Algorithmic patterns, we use single pattern
///which will extract all three things by combining the three patterns in one.
class lineSum : public Summation<Game, sumResult>
{
    sumResult func(const Game& e) const override { return sumResult(e.name == "highjump", e.rank, e.rank == 2 ? 1 : 0 ); }
    sumResult neutral() const override { return sumResult(false, 99999, 0);}
    sumResult add( const sumResult& a, const sumResult& b) const override
    {
        return sumResult(a.highJump || b.highJump, a.bestRank < b.bestRank ? a.bestRank : b.bestRank,a.silverMedals + b.silverMedals );
    }
};

struct Contestant {
    string name;
    string school;
    bool highJump;
    int bestrank;
    int silvers;
    friend istream& operator>>(istream &is, Contestant &c);
};
///running100 2 highjump 10
istream& operator>>(istream &is, Contestant &c)
{
    string line;
    getline(is, line);
    stringstream ss(line);

    ss >> c.name >> c.school;

    lineSum pr;
    StringStreamEnumerator<Game> ssenor(ss);
    pr.addEnumerator(&ssenor);

    pr.run();

    c.highJump = pr.result().highJump;
    c.bestrank = pr.result().bestRank;
    c.silvers = pr.result().silverMedals;

///Solution b.
/*
    stringstream ss(line);
    stringstream ss1(line);
    stringstream ss2(line);
    string tmp;

    ss >> c.name >> c.school;
    ss1 >> tmp >> tmp;
    ss2 >> tmp >> tmp;


    highJumped pr;
    findBestRank pr1;
    countSilvers pr2;
    StringStreamEnumerator<Game> ssenor(ss);
    StringStreamEnumerator<Game> ssenor1(ss1);
    StringStreamEnumerator<Game> ssenor2(ss2);

    pr.addEnumerator(&ssenor);
    pr1.addEnumerator(&ssenor1);
    pr2.addEnumerator(&ssenor2);

    pr.run();
    pr1.run();
    pr2.run();

    c.highJump = pr.found();
    c.bestrank = pr1.opt();
    c.silvers = pr2.result();
*/
    return is;
}

class findHighJumper : public LinSearch<Contestant>
{
    bool cond(const Contestant& e) const override
    {
        return e.highJump && e.bestrank == 2;
    }
};


int main(int argc, char** argv)
{
    try
    {
        string filename;
        if (argc > 1)
            filename = argv[1];
        else
            filename = "input.txt";

        findHighJumper pr;

        SeqInFileEnumerator<Contestant> enor(filename);
        pr.addEnumerator(&enor);

        pr.run();

        if (pr.found())
        {
            cout << pr.elem().name << " from " << pr.elem().school << " has participated in highjump and has the best rank as silver, and no. of silvers is: " <<pr.elem().silvers <<endl;
        }else
        {
            cout << "There was no such highJumper\n";
        }

    }catch (SeqInFileEnumerator<Contestant>::Exceptions ex)
    {
        cout << "File not found! \n";
    }
    return 0;
}
