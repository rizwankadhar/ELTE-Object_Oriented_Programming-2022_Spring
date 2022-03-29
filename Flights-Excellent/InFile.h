#ifndef INFILE_H
#define INFILE_H

#include <iostream>

#include <fstream>

enum Status { norm , abnorm };


struct Flight{
    std::string date;
    std::string id;
    int PC;
    int NoP;

    friend std::istream &operator>>(std::istream &is, Flight &f)
    {
        is >> f.date >> f.id >> f.PC >> f.NoP;
        return is;
    }

};

struct Day {
    std::string date;
    int cntFlights;
};

class InFile
{
    public:


        enum Errors { FILE_ERROR };

        InFile(const std::string &filename);
        ~InFile() {_x.close(); }

        void first () { read(); next(); }
        void next();
        Day current() const { return _cur;}
        bool end() const { return _end; }

    private:
        ///st, e, f : read
        Status _sx;
        Flight _dx;
        std::ifstream _x;

        bool _end;

        Day _cur;

        void read();

};

#endif // INFILE_H
