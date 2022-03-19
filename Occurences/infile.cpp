#include "infile.h"

std::ostream &operator<<(std::ostream &os,const Occurrence &o)
{
    os << "Number: " << o.number << " occurrence: " << o.count;
}

inFile::inFile(const std::string &fileName)
{
    _x.open(fileName.c_str());
    if(_x.fail()) throw FILE_ERROR;
}

void inFile::next()
{
    if( !(_end = (abnorm==_sx) )){
/**
    _end = (abnorm==_sx);
    if (!_end) {
*/
        _cur.number = _dx;
        _cur.count = 0;
        for( ; norm==_sx && _dx==_cur.number ; read() ){
            _cur.count++;
        }
    }
}

void inFile::read()
{
    _sx = (_x >> _dx) ? norm : abnorm;
/**
    _x >> _dx;
    if ( _x.fail() ) _sx = abnorm;
    else _sx = norm;
*/
}
