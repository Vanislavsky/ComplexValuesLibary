#ifndef complex_h
#define complex_h

#include "rational.h"

class complex {
private:
    rational real_part;
    rational imaginary_part;

public:
    complex();

    complex(rational real_part, rational imaginary_part);

    complex(double value);

    complex(long long value);

    complex(int value);

    rational get_real_part();

    rational get_imaginary_part();

    void set_real_part(rational real_part);

    void set_imaginary_part(rational imaginary_part);

    complex& operator=(const complex& other);

    complex& operator=(int value);

    complex& operator=(long long value);

    complex& operator=(double value);

    complex& operator-();

    complex operator+(const complex& other) const;

    complex operator+(int value) const;

    complex operator-(const complex& other) const;

    complex operator-(int value) const;

    complex operator*(const complex& other) const;

    complex operator*(int value) const;

    complex operator/(const complex& other) const;

    complex operator/(int value);

    complex& operator+=(const complex& other);

    complex& operator+=(int value);

    complex& operator-=(const complex& other);

    complex& operator-=(int value);

    complex& operator*=(const complex& other);

    complex& operator*=(int value);

    complex& operator/=(const complex& other);

    complex& operator/=(int value);

    bool operator==(const complex& other) const;

    friend std::ostream& operator<< (std::ostream &out, const complex &value);
    friend complex abs(complex value);

};

#endif /* complex_h */
