#include<z3++.h>
#include<SSARI/ssari.h>
#include<gtest/gtest.h>
#include<cmath>
#include "z3Math.h"

using namespace z3;
using namespace std;
using namespace SSARI;

// Test Bool Greater Than
TEST(Z3Var, TestGT) {
    Z3Math operation;
    shared_ptr<SymbolicVar> four = operation.get(shared_ptr<CConstant>(new CConstant("4")));
    shared_ptr<SymbolicVar> x = operation.set(CVar("x") , four);
    shared_ptr<SymbolicVar> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<SymbolicVar> expr = operation.gt(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
}
/*
// Test Boolean Operations
// Greater than or Equal
TEST(Z3Var, TestGTE) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Var> expr = operation.gte(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Less than
TEST(Z3Var, TestLT) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Var> expr = operation.lt(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Less than or Equal
TEST(Z3Var, TestLTE) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Var> expr = operation.lte(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}

// Equal
TEST(Z3Var, TestEQ) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Var> expr = operation.eq(x, y);
    EXPECT_EQ(operation.isSat(expr), false);
}

// Not Equal
TEST(Z3Var, TestNEQ) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    shared_ptr<Z3Var> expr = operation.neq(x, y);
    EXPECT_EQ(operation.isSat(expr), true);
}
// Test Arithmetic Operations
// Addition
TEST(Z3Var, TestADD) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(14,operation.add(x, y));
}

// Subraction
TEST(Z3Var, TestSUB) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(-6,operation.sub(x, y));
}

// Multiplication
TEST(Z3Var, TestMUL) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(40,operation.mul(x, y));
}

// Division
TEST(Z3Var, TestDIV) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));
    EXPECT_EQ(14,operation.div(x, y));
}

// Test Logical Operations
// LogOr
TEST(Z3Var, TestlogOR) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.logOr(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// LogAnd
TEST(Z3Var, TestlogAND) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.logAnd(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), false);
}

// LogNot
TEST(Z3Var, TestlogNOT) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.logNot(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// Test Boolean Operations
// BoolOr
TEST(Z3Var, TestboolOR) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.boolOr(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}

// BoolAnd
TEST(Z3Var, TestboolAND) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.boolAnd(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), false);
}

//BoolNot
TEST(Z3Var, TestboolNOT) {
    Z3Math operation;
    shared_ptr<Z3Var> x = operation.set(CVar("x") , operation.get(shared_ptr<CConstant>(new CConstant("4"))));
    shared_ptr<Z3Var> y = operation.set(CVar("y") , operation.get(shared_ptr<CConstant>(new CConstant("10"))));

    shared_ptr<Z3Var> expr1 = operation.gt(x, y);
    shared_ptr<Z3Var> expr2 = operation.lt(x, y);
    shared_ptr<Z3Var> expr3 = operation.boolNot(expr1, expr2);

    EXPECT_EQ(operation.isSat(expr3), true);
}
*/

