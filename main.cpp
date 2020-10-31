#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "test.h"
#include "complex.h"
#include "rational.h"
using namespace std;


int main(int argc, char* argv[]) {
    testing::InitGoogleTest(&argc, argv);
    RUN_ALL_TESTS();

    complex a = 5;
    cout << a;
    return 0;
}

