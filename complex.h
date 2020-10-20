#ifndef complex_h
#define complex_h

#include "rational.h"

class complex {
private:
    rational real_part;
    rational imaginary_part;

public:
    complex(rational real_part, rational imaginary_part): real_part{real_part}, imaginary_part{imaginary_part} {}

    complex(double value): real_part(value), imaginary_part(0) {}

    complex(long long value): real_part{value}, imaginary_part{0} {}

    complex(int value): real_part{value}, imaginary_part{0} {}

    rational get_real_part() {
        return real_part;
    }

    rational get_imaginary_part() {
        return imaginary_part;
    }

    void set_real_part(rational real_part) {
        this->real_part = real_part;
    }

    void set_imaginary_part(float imaginary_part) {
        this->imaginary_part = imaginary_part;
    }

    complex& operator=(complex& other) {
        real_part = other.real_part;
        imaginary_part = other.imaginary_part;
        return *this;
    }

    complex& operator=(long long value) {
        real_part = value;
        imaginary_part = 0;
        return *this;
    }

    complex& operator=(double value) {
        real_part = value;
        imaginary_part = 0;
        return *this;
    }

    complex& operator-() {
        real_part.numerator = -real_part.numerator;
        imaginary_part.numerator = -imaginary_part.numerator;
        return *this;
    }

    complex operator+(complex& other) {
        return {real_part + other.real_part, imaginary_part + other.imaginary_part};
    }

    complex operator+(int value) {
        return {real_part + value, imaginary_part};
    }

    complex operator-(complex& other) {
        return {real_part - other.real_part, imaginary_part - other.imaginary_part};
    }

    complex operator-(int value) {
        return {real_part - value, imaginary_part};
    }

    complex operator*(complex& other) {
        rational r_part = real_part * other.real_part + imaginary_part * other.imaginary_part * -1;
        rational im_part = imaginary_part * other.real_part + real_part * other.imaginary_part;
        return {r_part, im_part};
    }

    complex operator*(int value) {
        return {real_part * value, imaginary_part * value};
    }

    complex operator/(complex& other) {
        auto r_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
        auto im_part = (other.real_part * imaginary_part - other.imaginary_part * real_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
        return {r_part, im_part};
    }

    complex operator/(int value) {
        return {real_part / value, imaginary_part / value};
    }

    complex& operator+=(complex& other) {
        real_part = real_part + other.real_part;
        imaginary_part = imaginary_part + other.imaginary_part;
        return *this;
    }

    complex& operator+=(int value) {
        real_part = real_part + value;
        return *this;
    }

    complex& operator-=(complex& other) {
        this->real_part = this->real_part - other.real_part;
        this->imaginary_part = this->imaginary_part - other.imaginary_part;
        return *this;
    }

    complex& operator-=(int value) {
        real_part = real_part - value;
        return *this;
    }

    complex& operator*=(complex& other) {
        real_part = real_part * other.real_part + imaginary_part * other.imaginary_part * -1;
        imaginary_part = imaginary_part * other.real_part + real_part * other.imaginary_part;
        return *this;
    }

    complex& operator*=(int value) {
        real_part = real_part * value;
        imaginary_part = imaginary_part * value;
        return *this;
    }

    complex& operator/=(complex& other) {
        real_part = (real_part * other.real_part + imaginary_part * other.imaginary_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
        imaginary_part = (other.real_part * imaginary_part - other.imaginary_part * real_part) / (other.real_part * other.real_part + other.imaginary_part * other.imaginary_part);
        return *this;
    }

    complex& operator/=(int value) {
        real_part = real_part / value;
        imaginary_part = imaginary_part / value;
        return *this;
    }

    bool operator==(complex& other) {
        if(real_part == other.real_part && imaginary_part == other.imaginary_part)
            return true;
        else
            return false;
    }

    friend std::ostream& operator<< (std::ostream &out, const complex &value);
    friend complex abs(complex value);

};

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

#endif /* complex_h */
