#include<z3++.h>
#include<ssari.h>
#include<gtest/gtest.h>
#include<cmath>

using namespace std;
using namespace SSARI;

// Test Bool Greater Than
TEST(BoolFunction, TestGT) {
    BoolFunc a("a");
    BoolFunc b("b");


    EXPECT_GT(a, b);

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


