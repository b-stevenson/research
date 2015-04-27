#include<z3++.h>
#include<ssari.h>
#include<gtest/gtest.h>
#include<cmath>

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than (W.I.P.)
TEST(z3Math, TestGT) {
    z3Math a("a");
    z3Math b("b");

    z3Math expr1 = a > b;
    EXPECT_EQ(expr1.toString(), "(X_0>Y_0)");

}

// Test Bool Greater than or Equal
TEST(BoolFunction, TestGTE) {
    BoolFunc a("a");
    BoolFunc b("b");


    EXPECT_GE(a, b);

}

// Test Bool Equal
TEST(BoolFunction, TestEQ) {
    EXPECT_EQ(6,sqrt(36));

}


