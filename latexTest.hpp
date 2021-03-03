#ifndef __LATEXTEST_HPP__
#define __LATEXTEST_HPP__

#include <iostream>
#include "base.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "mult.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "op.hpp"
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
}

TEST(LaTeX, test5)
{
    Base* two1 = new Op(2);
    Base* five1 = new Op(5);
    Base* two2 = new Op(2);
    Base* five2 = new Op(5);
    Mult* mult = new Mult(two1, five1);
    Pow* pow = new Pow(five2, two2);
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
}

#endif
