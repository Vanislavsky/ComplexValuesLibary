#ifndef _rational_h
#define _rational_h

#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

class rational {
private:
    long long numerator;
    long long denominator;
public:
    friend unsigned int GCD(unsigned long long u, unsigned long long v);

    rational();

    rational(long long num, long long den);

    rational(int num, int den);

    rational(long long num);

    rational(int num);

    rational(double value);

    long long get_numerator() const;

    long long get_denomenator() const;

    void set_numerator(long long value);

    void set_denomenator(long long value);

    rational& operator= (double value);

    rational& operator= (long long value);

    rational& operator= (int value);

    rational& operator= (const rational& other);

    rational operator+ (const rational& other) const;

    rational operator- (const rational& other) const;

    rational operator* (const rational& other) const;

    rational operator/ (const rational& other) const;

    bool operator==(const rational& other) const;

    friend class complex;

    friend std::ostream& operator<< (std::ostream &out, const rational &value);

    friend rational abs(rational value);

    friend double arctan(rational l_value, rational r_value);
};


#endif /* _rational_h */
