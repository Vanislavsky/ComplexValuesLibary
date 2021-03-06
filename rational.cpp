#include "rational.h"

unsigned int GCD(unsigned long long u, unsigned long long v) {
    while ( v != 0) {
        unsigned long long r = u % v;
        u = v;
        v = r;
    }
    return u;
}

rational::rational() {
    numerator = 0;
    denominator = 1;
}

rational::rational(long long num, long long den) {
    numerator = num;
    if(den < 0) {
        numerator *= -1;
    }
    denominator = abs(den);

    auto divider = GCD(abs(num), abs(den));
    numerator /= divider;
    denominator /= divider;

}

rational::rational(int num, int den) {
    numerator = num;
    if(den < 0) {
        numerator *= -1;
    }
    denominator = abs(den);

    auto divider = GCD(abs(num), abs(den));
    numerator /= divider;
    denominator /= divider;

}

rational::rational(long long num): numerator{num}, denominator{1} {}

rational::rational(int num): numerator{num}, denominator{1} {}

rational::rational(double value) {
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

long long rational::get_numerator() const {
    return numerator;
}

long long rational::get_denomenator() const {
    return denominator;
}

void rational::set_numerator(long long value) {
    numerator = value;
}

void rational::set_denomenator(long long value) {
    denominator = value;
}

rational& rational::operator= (double value) {
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

rational&  rational::operator= (long long value) {
    numerator = value;
    denominator = 1;
    return *this;
}

rational& rational::operator= (int value) {
    numerator = value;
    denominator = 1;
    return *this;
}

rational& rational::operator= (const rational& other) {
    numerator = other.numerator;
    denominator = other.denominator;
    return *this;
}

rational rational::operator+ (const rational& other) const {
    return {numerator * other.denominator + other.numerator * denominator, denominator * other.denominator};
}

rational rational::operator- (const rational& other) const {
    return {numerator * other.denominator - other.numerator * denominator, denominator * other.denominator};
}

rational rational::operator* (const rational& other) const {
    return {numerator * other.numerator, denominator * other.denominator};
}

rational rational::operator/ (const rational& other) const {
    return {numerator * other.denominator, denominator * other.numerator};
}

bool rational::operator==(const rational& other) const {
    if(numerator == other.numerator && denominator == other.denominator)
        return true;
    else
        return false;
}

std::ostream& operator<< (std::ostream &out, const rational &value) {
    if(value.denominator != 1)
        out << value.numerator << "/" << value.denominator;
    else
        out << value.numerator;
    return out;
}

rational abs(rational value) {
    if(value.numerator < 0)
        value.numerator = value.numerator * -1;
    return value;
}

double arctan(rational l_value, rational r_value) {
    auto x_coord = l_value.get_numerator() / l_value.get_denomenator();
    auto y_coord = r_value.get_numerator() / r_value.get_denomenator();
    return atan2(x_coord, y_coord);
}
