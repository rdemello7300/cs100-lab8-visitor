#ifndef ___operandTest___
#define ___operandTest___

#include <iostream>
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "op.hpp"
#include "iterator.hpp"

using namespace std;

TEST(numChild1, Two_Child_Using_Add)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> number_of_children(), 2); 

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

   EXPECT_EQ(div -> number_of_children(), 4);
   EXPECT_EQ(div -> evaluate(), 4);

}

TEST(numChild3, One__Child_Using_Add)
{
   Base* num1 = new Op(2);

   EXPECT_EQ(num1 -> number_of_children(), 1);

}

TEST(GetChild1, Two_child_Return_Left)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> get_child(0) -> evaluate(), 2);

}

TEST(GetChild2, Two_child_Return_Right)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);

   Add* test = new Add(num1, num2);
   EXPECT_EQ(test -> get_child(1) -> evaluate(), 3);

}


#endif
