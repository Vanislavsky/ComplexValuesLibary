#ifndef _rational_h
#define _rational_h

#include <string>
#include <iostream>
#include <algorithm>
#include <math.h>

unsigned int GCD(unsigned long long u, unsigned long long v);

class rational {
private:
    long long numerator;
    long long denominator;
public:


    rational() {
        numerator = 0;
        denominator = 1;
    }

    rational(long long num, long long den) {
        numerator = num;
        if(den < 0) {
            numerator *= -1;
        }
        denominator = abs(den);

        auto divider = GCD(abs(num), abs(den));
        numerator /= divider;
        denominator /= divider;

    }

    rational(int num, int den) {
        numerator = num;
        if(den < 0) {
            numerator *= -1;
        }
        denominator = abs(den);

        auto divider = GCD(abs(num), abs(den));
        numerator /= divider;
        denominator /= divider;

    }

    rational(long long num): numerator{num}, denominator{1} {}

    rational(int num): numerator{num}, denominator{1} {}

    rational(double value) {
        std::string  str_num = std::to_string(value);
        size_t pos = str_num.find('.');
        int number_digits = str_num.size() - 1 - pos;
        double num = value * pow(10, number_digits);
        numerator = num;
        denominator = pow(10, number_digits);
        unsigned int divider = GCD(abs(numerator), abs(denominator));
        numerator /= divider;
        denominator /= divider;
    }

    long long get_numerator() {
        return numerator;
    }

    long long get_denomenator() {
        return denominator;
    }

    void set_numerator(long long value) {
        numerator = value;
    }

    void set_denomenator(long long value) {
        denominator = value;
    }

    rational& operator= (double value) {
        std::string  str_num = std::to_string(value);
        size_t pos = str_num.find('.');
        int number_digits = str_num.size() - 1 - pos;
        double num = value * pow(10, number_digits);
        numerator = num;
        denominator = pow(10, number_digits);
        unsigned int divider = GCD(numerator, denominator);
        numerator /= divider;
        denominator /= divider;
        return *this;
    }

    rational& operator= (long long value) {
        numerator = value;
        denominator = 1;
        return *this;
    }

    rational& operator= (int value) {
        numerator = value;
        denominator = 1;
        return *this;
    }

    rational& operator= (rational other) {
        numerator = other.numerator;
        denominator = other.denominator;
        return *this;
    }

    rational operator+ (rational other) {
        return {numerator * other.denominator + other.numerator * denominator, denominator * other.denominator};
    }

    rational operator+ (long long value) {
        return {numerator + value * denominator , denominator};
    }

    rational operator- (rational other) {
        return {numerator * other.denominator - other.numerator * denominator, denominator * other.denominator};
    }

    rational operator- (long long value) {
        return {numerator - value * denominator , denominator};
    }

    rational operator* (rational other) {
        return {numerator * other.numerator, denominator * other.denominator};
    }

    rational operator* (long long value) {
        return {numerator * value, denominator};
    }

    rational operator/ (rational other) {
        return {numerator * other.denominator, denominator * other.numerator};
    }

    rational operator/ (long long value) {
        return {numerator, denominator * value};
    }

    bool operator==(rational other) {
        if(numerator == other.numerator && denominator == other.denominator)
            return true;
        else
            return false;
    }

    friend class complex;
    friend std::ostream& operator<< (std::ostream &out, const rational &value);
    friend rational abs(rational value);
};

std::ostream& operator<< (std::ostream &out, const rational &value) {
    if(value.denominator != 1)
        out << value.numerator << "/" << value.denominator;
    else
        out << value.numerator;
    return out;
}

unsigned int GCD(unsigned long long u, unsigned long long v) {
    while ( v != 0) {
        unsigned long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

rational abs(rational value) {
    if(value.numerator < 0)
        value.numerator = value.numerator * -1;
    return value;
}

#endif /* _rational_h */
