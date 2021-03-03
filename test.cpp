#include "gtest/gtest.h"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"
#include <stdio.h>
#include <iostream>
#include "iterator.hpp"
#include "visitor.hpp"
#include "mathml.cpp"
#include "operandTest.cpp"
#include "MathmlTest.cpp"
using namespace std;

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
