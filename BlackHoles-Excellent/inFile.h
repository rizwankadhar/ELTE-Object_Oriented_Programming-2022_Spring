#ifndef INFILE_H
#define INFILE_H

#include <fstream>
#include <vector>
#include <sstream>
#include <iostream>


struct Measurement
{
    std::string date;
    int weight;
    int distance;
    friend std::istream &operator>>(std::istream &is, Measurement &m);
};

struct Station ///blackhole
{
    std::string name;///CX896
    std::string station;///SOYUZ
    int lastWeight; ///9800
    bool close;///true
    friend std::istream &operator>>(std::istream &is, Station &s);
};

struct BlackHole
{
    std::string name;
    double avgOfWeights;
    bool allClose;
};

enum Status {norm, abnorm};


class inFile
{
    public:
        enum Error {FILE_ERROR};
        inFile(const std::string fileName);
        ~inFile() { _x.close(); }
        void first() { read(); next(); }
        void next();
        BlackHole current() const { return _cur; }
        bool end() const { return _end; }

    private:
        std::ifstream _x;
        Station _dx;
        Status _sx;
        bool _end;
        BlackHole _cur;

        void read();
};

#endif // INFILE_H
