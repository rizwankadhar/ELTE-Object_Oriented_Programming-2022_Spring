#include <iostream>
#include "library/linsearch.hpp"
#include "library/seqinfileenumerator.hpp"
#include "library/stringstreamenumerator.hpp"
#include "library/summation.hpp"
#include "library/enumerator.hpp"

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

class highJumped : public LinSearch<Game>
{
    bool cond(const Game& e) const override { return e.name == "highjump"; }
};

struct Student {
    string name;
    string school;

    bool highJump;

    friend istream& operator>>(istream &is, Student &s);

};

istream& operator>>(istream &is, Student &s)
{
    string line;

    getline(is, line);

    stringstream ss(line);
    ss >> s.name >> s.school;

    highJumped pr;
    StringStreamEnumerator<Game> ssenor(ss);

    pr.addEnumerator(&ssenor);

    pr.run();

    s.highJump = pr.found();

    return is;
}

struct School {
    string schoolName;
    int highJumpers;///Counting(Conditional)
    int participantsCnt;///Counting

    School() {}
    School(string name, int hJ, int pC): schoolName(name), highJumpers(hJ), participantsCnt(pC) {}
};


class countAll : public Summation<Student, School>
{
private:
    string _name;
public:
    countAll(const string &name) : _name(name) {}
protected:
    School func(const Student& e) const override { return School(e.school, e.highJump ? 1 : 0, 1);}
    School neutral() const override { return School("", 0, 0); }
    School add( const School& a, const School& b) const override
    {
        return School(b.schoolName, a.highJumpers + b.highJumpers, a.participantsCnt + b.participantsCnt);
    }

    bool whileCond(const Student& current) const { return current.school == _name; }
    void first() override { }
    ///("", 0 , 0) + (PPKE, 1, 1) = "PPKE", 1, 1
};



class SchoolEnor : public Enumerator<School>
{
private:
    SeqInFileEnumerator<Student>* _f;
    School _school;

    bool _end;

    bool _empty;

public:
    SchoolEnor(const string &fname) : _empty(true) { _f = new SeqInFileEnumerator<Student>(fname);}
    ~SchoolEnor() { delete _f;}

     void first() override { _f->first(); next(); if (!end()) _empty = false; }
     void next() override;
    bool end() const override { return _end;}
    School current() const override {return _school;}

    bool isEmpty() const { return _empty;}
};

void SchoolEnor::next()
{
    _end = _f->end();
    if (_end) return;

    _school.schoolName = _f->current().school;

    countAll pr(_school.schoolName);
    pr.addEnumerator(_f);

    pr.run();

    _school.highJumpers = pr.result().highJumpers;
    _school.participantsCnt = pr.result().participantsCnt;
}

class Output : public Summation<School, ostream>
{

public:
    Output(ostream *o) : Summation<School, ostream>::Summation(o) {}
protected:
    std::string func(const School& e) const override
    {
        ostringstream oss;
        oss << e.schoolName << ", highjumpers:" << e.highJumpers << ", participants: " << e.participantsCnt << endl;
        return oss.str();
    }
    bool cond(const School& e) const { return e.highJumpers >= 10; }
};

int main(int argc, char** argv)
{
    try {
        string filename;
        if (argc > 1)
        {
            filename = argv[1];
        }
        else
            filename = "input.txt";
        Output pr(&cout);
        SchoolEnor enor(filename);

        pr.addEnumerator(&enor);


        pr.run();
        if (enor.isEmpty())
        {
            cout << "File is empty\n";
        }

    }catch(SeqInFileEnumerator<Student>::Exceptions ex)
    {
        cout << "File not found!\n";
    }
    return 0;
}
