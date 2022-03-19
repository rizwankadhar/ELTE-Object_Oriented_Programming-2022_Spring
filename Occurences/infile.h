#pragma once

#include <fstream>
#include <iostream>

struct Occurrence {
    int number;
    int count;
    friend std::ostream &operator<<(std::ostream &os,const Occurrence &o);
};

enum Status { abnorm, norm };

class inFile
{
    public:
        enum Errors { FILE_ERROR };

        inFile(const std::string &fileName);
        ~inFile() { _x.close(); }
        void first() { read(); next(); }
        void next();
        Occurrence current() const { return _cur; }
        bool end() const { return _end; }
    private:
        std::ifstream _x;
        int _dx;
        Status _sx;

        Occurrence _cur;
        bool _end;

        void read();
};
