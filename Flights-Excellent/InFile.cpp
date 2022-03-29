#include "InFile.h"

InFile::InFile(const std::string &filename)
{
    _x.open(filename.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void InFile::read()
{
    _x >> _dx;
    if (_x.fail())
    {
        _sx = abnorm;
    }
    else
    {
        _sx = norm;
    }
}

void InFile::next()///02/01/22 ZTRH56 150 132
{
    _end = (_sx == abnorm);
    if (!_end)
    {
        _cur.date = _dx.date;
        _cur.cntFlights = 0;

        for (; _sx == norm && _dx.date == _cur.date ; read())
        {
            _cur.cntFlights++;
        }
    }
}

