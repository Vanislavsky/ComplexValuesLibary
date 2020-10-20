
#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "complex.h"
#include "rational.h"

TEST (ComplexValueTese, Sum) {
    complex a(rational(5), rational(-6));
    complex b(rational(-3), rational(2));
    complex c(rational(2), rational(-4));

}

TEST (SquareRootTest, ZeroAndNegativeNos) {

}

using namespace std;
int main(int argc, char* argv[]) {
    complex a(5, -6);
    complex b(-3, 2);
    complex c = a + b;
    cout << c;
    //testing::InitGoogleTest(&argc, argv);
    //RUN_ALL_TESTS();
    return 0;
}

