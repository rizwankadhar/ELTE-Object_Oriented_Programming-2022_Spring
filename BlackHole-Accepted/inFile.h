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

struct Blackhole///Useful data from one line of the file
{
    std::string name;///CX896
    int lastWeight; ///8500
    bool close;///true
    friend std::istream &operator>>(std::istream &is, Blackhole &s);
};


enum Status {norm, abnorm};

class inFileMax
{
    public:
        enum Error {FILE_ERROR};
        inFileMax(const std::string &fileName);
        ~inFileMax() { _x.close(); }
        void first() { read(); }///Data of one Blackhole is present in only one line, so the first() is similar to next()
        void next() { read(); }///We don't have to iterate over multiple lines to collect data about one Blackhole(as all
                             ///data of one blackhole is listed in single line), so next() is simple

        Blackhole current() const { return _dx; }///Same as the useful data from one line(as one line is containing all info
 						///about a blackhole)
        bool end() const {return _sx == abnorm; }

    private:
        std::ifstream _x;
        Blackhole _dx;
        Status _sx;

        void read();
};

#endif // INFILE_H
