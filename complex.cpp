#include "complex.h"
#include "rational.h"

complex::complex() {
    real_part = 0;
    imaginary_part = 0;
}

complex::complex(rational real_part, rational imaginary_part): real_part{real_part}, imaginary_part{imaginary_part} {}

complex::complex(double value): real_part(value), imaginary_part(0) {}

complex::complex(long long value): real_part{value}, imaginary_part{0} {}

complex::complex(int value): real_part{value}, imaginary_part{0} {}

rational complex::get_real_part() {
    return real_part;
}

rational complex::get_imaginary_part() {
    return imaginary_part;
}

void complex::set_real_part(rational real_part) {
    this->real_part = real_part;
}

void complex::set_imaginary_part(rational imaginary_part) {
    this->imaginary_part = imaginary_part;
}

complex& complex::operator=(const complex& other) {
    real_part = other.real_part;
    imaginary_part = other.imaginary_part;
    return *this;
}

complex& complex::operator=(int value) {
    real_part = value;
    imaginary_part = 0;
    return *this;
}

complex& complex::operator=(long long value) {
    real_part = value;
    imaginary_part = 0;
    return *this;
}

complex& complex::operator=(double value) {
    real_part = value;
    imaginary_part = 0;
    return *this;
}

complex& complex::operator-() {
    real_part.numerator = -real_part.numerator;
    imaginary_part.numerator = -imaginary_part.numerator;
    return *this;
}

complex complex::operator+(const complex& other) const {
    return {real_part + other.real_part, imaginary_part + other.imaginary_part};
}

complex complex::operator+(int value) const {
    return {real_part + value, imaginary_part};
}

complex complex::operator-(const complex& other) const {
    return {real_part - other.real_part, imaginary_part - other.imaginary_part};
}

complex complex::operator-(int value) const {
    return {real_part - value, imaginary_part};
}

complex complex::operator*(const complex& other) const {
    rational r_part = real_part * other.real_part + imaginary_part * other.imaginary_part * -1;
    rational im_part = imaginary_part * other.real_part + real_part * other.imaginary_part;
    return {r_part, im_part};
}

complex complex::operator*(int value) const {
    return {real_part * value, imaginary_part * value};
}

complex complex::operator/(const complex& other) const {
    rational r_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
    rational im_part = (other.real_part * imaginary_part - other.imaginary_part * real_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
    return {r_part, im_part};
}

complex complex::operator/(int value) {
    return {real_part / value, imaginary_part / value};
}

complex& complex::operator+=(const complex& other) {
    real_part = real_part + other.real_part;
    imaginary_part = imaginary_part + other.imaginary_part;
    return *this;
}

complex& complex::operator+=(int value) {
    real_part = real_part + value;
    return *this;
}

complex& complex::operator-=(const complex& other) {
    this->real_part = this->real_part - other.real_part;
    this->imaginary_part = this->imaginary_part - other.imaginary_part;
    return *this;
}

complex& complex::operator-=(int value) {
    real_part = real_part - value;
    return *this;
}

complex& complex::operator*=(const complex& other) {
    rational r_part = real_part * other.real_part + imaginary_part * other.imaginary_part * -1;
    rational im_part = imaginary_part * other.real_part + real_part * other.imaginary_part;
    real_part = r_part;
    imaginary_part = im_part;
    return *this;
}

complex& complex::operator*=(int value) {
    real_part = real_part * value;
    imaginary_part = imaginary_part * value;
    return *this;
}

complex& complex::operator/=(const complex& other) {
    rational r_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
    rational im_part = (other.real_part * imaginary_part - other.imaginary_part * real_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
    real_part = r_part;
    imaginary_part = im_part;
    return *this;
}

complex& complex::operator/=(int value) {
    real_part = real_part / value;
    imaginary_part = imaginary_part / value;
    return *this;
}

bool complex::operator==(const complex& other) const {
    if(real_part == other.real_part && imaginary_part == other.imaginary_part)
        return true;
    else
        return false;
}

std::ostream& operator<< (std::ostream &out, complex &value) {
    auto digit = value.get_imaginary_part().get_numerator() >= 0 ? " + " : " - ";
    out << value.get_real_part() << digit << abs(value.get_imaginary_part()) << "*i";
    return out;
}

complex abs(complex value) {
    if(value.real_part.get_numerator() < 0)
        value.real_part.set_numerator(value.real_part.get_numerator() * -1);
    if(value.imaginary_part.get_numerator() < 0)
        value.imaginary_part.set_numerator(value.imaginary_part.get_numerator() * -1);
    return value;
}