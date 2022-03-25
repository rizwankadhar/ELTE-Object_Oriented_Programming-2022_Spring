#include "inFile.h"

std::istream &operator>>(std::istream &is, Measurement &m)
{
    is >> m.date >> m.weight >> m.distance;
    return is;
}

std::istream &operator>>(std::istream &is, Blackhole &st)///Extracting useful data from one line
{
    std::string line;
    getline(is,line,'\n');
    std::stringstream ss(line);
    ss >> st.name;
    st.close = false;
    st.lastWeight = 0;
    Measurement m;///1978.09.22 6000 3000

    while (ss >> m)
    {
        st.close = st.close || (m.distance < 2700);
        st.lastWeight = m.weight;
    }
    return is;
}


inFileMax::inFileMax(const std::string &fileName)
{
    _x.open(fileName.c_str());
    if (_x.fail()) throw FILE_ERROR;
}

void inFileMax::read()
{
    /// variable = condition ? value if true : value if false;
    _sx = (_x >> _dx) ? norm : abnorm;
}
