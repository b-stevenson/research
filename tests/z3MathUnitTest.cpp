#include<z3++.h>
#include<ssari.h>
#include<gtest/gtest.h>
#include<cmath>
#include<z3test.h>

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than
TEST(z3Math, TestGT) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr = operation.gt(x, y);
    EXPECT_EQ(operation.isSat(expr), false);

}
// Test Boolean Operations
// Greater than or Equal
TEST(z3Math, TestGTE) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.gte(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Less than
TEST(z3Math, TestLT) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.lt(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Less than or Equal
TEST(z3Math, TestLTE) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.lte(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Equal
TEST(z3Math, TestEQ) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.eq(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Not Equal
TEST(z3Math, TestNEQ) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Math> expr = operation.neq(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}
// Test Arithmetic Operations
// Addition
TEST(z3Math, TestADD) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(14,operation.add(x, y));
}

// Subraction
TEST(z3Math, TestSUB) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(-6,operation.sub(x, y));
}

// Multiplication
TEST(z3Math, TestMUL) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(40,operation.mul(x, y));
}

// Division
TEST(z3Math, TestDIV) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(14,operation.div(x, y));
}

// Test Logical Operations
// LogOr
TEST(z3Math, TestlogOR) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.logOr(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// LogAnd
TEST(z3Math, TestlogAND) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.logAnd(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), false);
}

// LogNot
TEST(z3Math, TestlogNOT) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.logNot(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// Test Boolean Operations
// BoolOr
TEST(z3Math, TestboolOR) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.boolOr(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// BoolAnd
TEST(z3Math, TestboolAND) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.boolAnd(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), false);
}

//BoolNot
TEST(z3Math, TestboolNOT) {
    z3Operations operation;
    shared_ptr<Z3Math> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Math> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Math> expr1 = operation.gt(x, y);
    shared_ptr<Z3Math> expr2 = operation.lt(x, y);
    shared_ptr<Z3Math> expr3 = operation.boolNot(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}


