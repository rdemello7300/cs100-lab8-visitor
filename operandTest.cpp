#ifndef ___operandTest___
#define ___operandTest___

#include "gtest/gtest.h"
#include "base.hpp"
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
#include "operandTest.cpp"
#include "visitor.hpp"

using namespace std;

TEST(numChild1, Two_Child_Using_Add)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> number_of_children(), 2); 

   delete num1;
   delete num2;
   delete test;
}

TEST(numChild2, Four_children)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);
   Base* num3 = new Op(4);
   Base* num4 = new Op(5);

   Add* test = new Add(num1, num2);
   Mult* mult = new Mult(test, num3);
   Div* div = new Div(mult, num4);

   EXPECT_EQ(div -> number_of_children(), 2);
   EXPECT_EQ(div -> evaluate(), 4);

   delete num1;
   delete num2;
   delete num3;
   delete num4;
   delete test;
   delete mult;
   delete div;
}

TEST(numChild3, One__Child_Using_Add)
{
   Base* num1 = new Op(2);

   EXPECT_EQ(num1 -> number_of_children(), 0);

   delete num1;
}

TEST(GetChild1, Two_child_Return_Left)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> get_child(0) -> evaluate(), 2);

   delete num1;
   delete num2;
   delete test;
}

TEST(GetChild2, Two_child_Return_Right)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> get_child(1) -> evaluate(), 3);

   delete num1;
   delete num2;
   delete test;
}

TEST(randTest, No_Child)
{
   Base* num1 = new Rand();

   EXPECT_EQ(num1 -> number_of_children(), 0);

   delete num1;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

#endif
