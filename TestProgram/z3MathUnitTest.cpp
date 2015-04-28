#include<z3++.h>
#include<ssari.h>
#include<gtest/gtest.h>
#include<cmath>
#include<z3test.h>

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than (W.I.P.)
TEST(z3Math, TestGT) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.gt(x, y);
    EXPECT_EQ(operation.isSat(expr), false);

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


