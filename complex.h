#ifndef complex_h
#define complex_h

#include "rational.h"

class complex {
private:
    rational real_part;
    rational imaginary_part;

public:
    complex();

    complex(const rational& real_part,const rational& imaginary_part);

    complex(double real_value, double im_value = 0);

    complex(long long real_value, long long im_value = 0);

    complex(int real_value, int im_value = 0);

    rational get_real_part() const;

    rational get_imaginary_part() const;

    void set_real_part(const rational& real_part);

    void set_imaginary_part(const rational& imaginary_part);

    complex& operator=(const complex& other);

    complex& operator=(int value);

    complex& operator=(long long value);

    complex& operator=(double value);

    complex& operator-();

    complex operator+(const complex& other) const;

    complex operator-(const complex& other) const;

    complex operator*(const complex& other) const;

    complex operator/(const complex& other) const;

    complex& operator+=(const complex& other);

    complex& operator-=(const complex& other);

    complex& operator*=(const complex& other);

    complex& operator/=(const complex& other);

    bool operator==(const complex& other) const;

    friend std::ostream& operator<< (std::ostream &out, const complex &value);

    friend const complex abs(complex value);

    friend const complex pow(complex value, int n);

    friend const rational arg(complex value);

};

#endif /* complex_h */
