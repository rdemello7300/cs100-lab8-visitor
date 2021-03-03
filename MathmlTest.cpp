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
#include "visitor.hpp"
#include "mathml.cpp"

using namespace std;

TEST(MathML1, Math_two_op_Add)
{
   Base* num1 = new Op(2);
   Base* num2 = new Op(3);
   Add* test = new Add(num1, num2);

   Iterator* ater = new Iterator(test);
    Mathml math;
    while(!ater -> is_done())
    {
        if(ater -> current_node() != NULL)
            ater -> current_node() -> accept(&math, ater -> current_index());
            ater -> next();
    }
   string testString = "<math>\n  <apply>\n    <plus/>\n    <cn>2.000000<cn>\n    <cn>3.000000<cn>\n  </apply>\n  </apply>\n</math>";
   EXPECT_EQ(math.PrintMath(test), testString);
}

TEST(MathML2, Multiple_ops)
{
    Base* four = new Op(4);
    Base* five = new Op(5);
    Base* two = new Op(2);
    Base* three = new Op(3);
    Mult* multi = new Mult(four, three);
    Add* addi1 = new Add(multi, two);
    Div* divi = new Div(addi1, five);
    
    Iterator* ater = new Iterator(divi);

    Mathml math;

    while(!ater -> is_done())
    {
        if(ater -> current_node() != NULL)
            ater -> current_node() -> accept(&math, ater -> current_index());
            ater -> next();
    }

    string tempStr = "<math>\n  <apply>\n    <divide/>\n      <plus/>\n        <times/>\n        <cn>4.000000<cn>\n        <cn>3.000000<cn>\n      </apply>\n        <cn>2.000000<cn>\n      </apply>\n        <cn>5.000000<cn>\n      </apply>\n  </apply>\n</math>";
    EXPECT_EQ(math.PrintMath(divi), tempStr);
}

TEST(MathML3, One_op)
{
    Base* four = new Op(4);
    Iterator* ater = new Iterator(four);
    Mathml math;
    while(!ater -> is_done())
    {
        if(ater -> current_node() != NULL)
            ater -> current_node() -> accept(&math, ater -> current_index());
            ater -> next();
    }

   string tempStr = "<math>\n  <apply>\n  <cn>4.000000<cn>\n  </apply>\n</math>";
   EXPECT_EQ(math.PrintMath(four), tempStr);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
