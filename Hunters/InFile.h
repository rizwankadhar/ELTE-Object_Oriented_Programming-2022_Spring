#ifndef INFILE_H
#define INFILE_H
#include <iostream>
#include <fstream>

struct Hunt {
    std::string hunter;
    std::string prey;

    int weight;

    friend std::istream &operator>>(std::istream &is, Hunt &h);
};

struct Hunter {
    std::string name;
    bool shotRabbit;///a.
    int cntHunts;///b.
};


enum Status { norm, abnorm };

class InFile
{
    public:

        enum ERRORS { FILE_ERROR } ;

        InFile(const std::string &filename);
        ~InFile() { _x.close(); }

        void first() { read(); next(); }
        void next();

        Hunter current() const { return _cur; }
        bool end() const { return _end; } /// return _sx == abnorm }

    private:
    ///st, e, f : read
    std::ifstream _x;
    Status _sx;
    Hunt _dx;

    Hunter _cur;
    bool _end;

    void read();

};

#endif // INFILE_H
