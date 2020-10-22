#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "complex.h"
#include "rational.h"

TEST (ComplexValueTest, Sum) {
    {
        complex a(5, -6);
        complex b(-3, 2);
        complex c(2, -4);
        ASSERT_TRUE((a + b) == c);
    }

    {
        complex a(5, -6);
        complex b(-3, 2);
        a += b;
        complex c(2, -4);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, SumRatValueas) {
    {
        complex a(0.75, 1.3);
        complex b(0.5, -0.8);
        complex c(rational(5, 4), rational(1, 2));
        ASSERT_TRUE((a + b) == c);
    }

    {
        complex a(0.75, 1.3);
        complex b(0.5, -0.8);
        a += b;
        complex c(rational(5, 4), rational(1, 2));
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, SumInt) {
    {
        complex a(5, -6);
        complex c(7, -6);
        ASSERT_TRUE((a + 2) == c);
    }

    {
        complex a(5, -6);
        a += 2;
        complex c(7, -6);
        ASSERT_TRUE(a == c);
    }
}


TEST (ComplexValueTest, Dif) {
    {
        complex a(3, 1);
        complex b(5, -2);
        complex c(-2, 3);
        ASSERT_TRUE((a - b) == c);
    }

    {
        complex a(3, 1);
        complex b(5, -2);
        a -= b;
        complex c(-2, 3);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, DifRatValues) {
    {
        complex a(1.77, 3.3);
        complex b(1.79, 1.7);
        complex c(rational(1, -50), rational(1.6));
        ASSERT_TRUE((a - b) == c);
    }

    {
        complex a(1.77, 3.3);
        complex b(1.79, 1.7);
        a -= b;
        complex c(rational(1, -50), rational(1.6));
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, DifInt) {
    {
        complex a(5, -6);
        complex c(3, -6);
        ASSERT_TRUE((a - 2) == c);
    }

    {
        complex a(5, -6);
        a -= 2;
        complex c(3, -6);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, Mult) {
    {
        complex a(2, 3);
        complex b(-1, 1);
        complex c(-5, -1);
        ASSERT_TRUE((a * b) == c);
    }

    {
        complex a(2, 3);
        complex b(-1, 1);
        a *= b;
        complex c(-5, -1);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, MultRatValues) {

}

TEST (ComplexValueTest, MultInt) {
    {
        complex a(2, 3);
        complex c(4, 6);
        ASSERT_TRUE((a * 2) == c);
    }

    {
        complex a(2, 3);
        a *= 2;
        complex c(4, 6);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, Div) {
    {
        complex a(-2, 1);
        complex b(1, -1);
        complex c(-1.5, -0.5);
        ASSERT_TRUE((a / b) == c);
    }

    {
        complex a(-2, 1);
        complex b(1, -1);
        a /= b;
        complex c(-1.5, -0.5);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, DivInt) {
    {
        complex a(2, 4);
        complex c(1, 2);
        ASSERT_TRUE((a / 2) == c);
    }

    {
        complex a(2, 4);
        a /= 2;
        complex c(1, 2);
        ASSERT_TRUE(a == c);
    }
}

TEST (ComplexValueTest, Assigment) {
    {
        complex a;
        a = 0.50;
        complex b;
        complex c = b = -a;
        ASSERT_TRUE(c == a);
    }
}

TEST (ComplexValueTest, Inequality) {
    {
        complex a = 2.5;
        complex b = 2;
        ASSERT_FALSE(a == b);
    }

    {
        complex a;
        a = 3;
        complex b;
        b = (long long)9299111324365555555;
        ASSERT_FALSE(a == b);
    }
}

TEST (ComplexValueTest, Abs) {
    {
        complex a(rational(-3,2), rational(-2,2));
        complex b(rational(3,2), rational(2,2));
        ASSERT_TRUE(b == abs(a));
    }

    {
        complex a(rational(3,2), rational(2,2));
        complex b(rational(3,2), rational(2,2));
        ASSERT_TRUE(b == abs(a));
    }

    {
        complex a(rational(3, 2), rational(-2, 2));
        complex b(rational(3, 2), rational(2, 2));
        ASSERT_TRUE(b == abs(a));
    }

    {
        complex a(rational(-3, 2), rational(2, 2));
        complex b(rational(3, 2), rational(2, 2));
        ASSERT_TRUE(b == abs(a));
    }
}




using namespace std;
int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();
    //complex a(0.5, -1.2);
    //cout << a;
    return 0;
}

