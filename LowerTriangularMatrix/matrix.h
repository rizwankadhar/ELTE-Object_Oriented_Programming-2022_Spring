#ifndef MATRIX_H
#define MATRIX_H
#include <vector>
#include <fstream>
#include <math.h>


using namespace std;

class matrix
{
    public:
        /// Exceptions - please explain briefly what an exception is
        class InvalidIndexException : public std::exception{};
        class OutOfTriangleException : public std::exception{};
        class DimensionMismatchException : public std::exception{};
        class InvalidVectorException : public std::exception{};

        /// Constructors
        matrix();
        matrix(int size);
        matrix(const std::string &fileName);

        /// Getters
        int getSize() const { return _size; }
        int getElement(int i,int j) const;

        /// Setters
        void setVec(const std::vector<int> &vec);
        void setElement(int i,int j,int e);

        /// Static methods
        static matrix add(const matrix& a,const matrix& b); ///operators come later, static methods are shown on the lecture
        static matrix multiply(const matrix& a,const matrix& b);

        /// Operator overload
        friend std::ostream &operator<<(std::ostream &os,const matrix& m);

    private:
        /// Private attributes
        std::vector<int> _vec;
        int _size;
        static int x;

        /// Private methods
        int ind(int i,int j) const;
        double calcSizeFromLength(unsigned int size);
        bool inLowerTrng(int i,int j) const;
};

#endif // MATRIX_H
