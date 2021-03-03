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
#include "visitorLatex.hpp"

using namespace std;

TEST(LaTeX, test1)
{
    Base* one = new Op(1);
    Base* five = new Op(5);
    Base* zero = new Op(0);
    Sub* sub = new Sub(five, zero);
    Add* add = new Add(one, sub);
    
    Iterator* it = new Iterator(add);
    VisitorLaTeX v;
        
    while(!it -> is_done())
    {
        if(it -> current_node() != NULL)
        {
            it -> current_node() -> accept(&v, it -> current_index());
            it -> next();
        }
    }
    
    cout << endl;
    cout << "Printing latex: " << v.PrintLaTeX(add) << endl;
    
    EXPECT_EQ(v.PrintLaTeX(add), "${({1.000000}+{({5.000000}-{0.000000})})}$");

    delete one;
    delete five;
    delete zero;
    delete sub;
    delete add;
    delete it;
}

TEST(LaTeX, test2)
{
    Base* five = new Op(5);
    Base* two = new Op(2);
    Pow* pow = new Pow(five, two);
    
    Iterator* it = new Iterator(pow);
    VisitorLaTeX v;
        
    while(!it -> is_done())
    {
        if(it -> current_node() != NULL)
        {
            it -> current_node() -> accept(&v, it -> current_index());
            it -> next();
        }
    }
    
    cout << endl;
    cout << "Printing latex: " << v.PrintLaTeX(pow) << endl;
    
    EXPECT_EQ(v.PrintLaTeX(pow), "${({5.000000}^{2.000000})}$");

    delete two;
    delete five;
    delete pow;
    delete it;
}

TEST(LaTeX, test3)
{
    Base* two = new Op(2);
    Base* five = new Op(5);
    Mult* mult = new Mult(two, five);
    
    Iterator* it = new Iterator(mult);
    VisitorLaTeX v;
        
    while(!it -> is_done())
    {
        if(it -> current_node() != NULL)
        {
            it -> current_node() -> accept(&v, it -> current_index());
            it -> next();
        }
    }
    
    cout << endl;
    cout << "Printing latex: " << v.PrintLaTeX(mult) << endl;
    
    EXPECT_EQ(v.PrintLaTeX(mult), "${({2.000000}\\cdot{5.000000})}$");

    delete two;
    delete five;
    delete mult;
    delete it;
}

TEST(LaTeX, test4)
{
    Base* two = new Op(2);
    Base* three = new Op(3);
    Div* div = new Div(two, three);
    
    Iterator* it = new Iterator(div);
    VisitorLaTeX v;
        
    while(!it -> is_done())
    {
        if(it -> current_node() != NULL)
        {
            it -> current_node() -> accept(&v, it -> current_index());
            it -> next();
        }
    }
    
    cout << endl;
    cout << "Printing latex: " << v.PrintLaTeX(div) << endl;
    
    EXPECT_EQ(v.PrintLaTeX(div), "${\\frac{2.000000}{3.000000}}$");

    delete two;
    delete three;
    delete div;
    delete it;
}

TEST(LaTeX, test5)
{
    Base* two = new Op(2);
    Base* five = new Op(5);
    Mult* mult = new Mult(two, five);
    Pow* pow = new Pow(five, two);
    Div* div = new Div(mult, pow);
    
    Iterator* it = new Iterator(div);
    VisitorLaTeX v;
        
    while(!it -> is_done())
    {
        if(it -> current_node() != NULL)
        {
            it -> current_node() -> accept(&v, it -> current_index());
            it -> next();
        }
    }
    
    cout << endl;
    cout << "Printing latex: " << v.PrintLaTeX(div) << endl;
    
    EXPECT_EQ(v.PrintLaTeX(div), "${\\frac{({2.000000}\\cdot{5.000000})}{({5.000000}^{2.000000})}}$");

    delete two;
    delete five;
    delete mult;
    delete pow;
    delete div;
    delete it;
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}
