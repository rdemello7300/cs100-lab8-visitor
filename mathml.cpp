#ifndef __MATHML_HPP__
#define __MATHML_HPP__

#include "visitor.hpp"
#include <iostream>
#include "base.hpp"
#include "op.hpp"
#include "add.hpp"
#include "mult.hpp"
#include "sub.hpp"
#include "div.hpp"
#include "pow.hpp"
#include "rand.hpp"

class Mathml: public Visitor
{
    protected:
        std::string str = "<math>\n  <apply>";
        int num = 1;
        
    public:
    Mathml() {}
        
    void visit_op (Op* node){
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<cn>" + node -> stringify() + "</cn>";
    }
    
    void visit_rand(Rand* node){
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<cn>" + node -> stringify() + "</cn>";
    }
    
    void visit_add_begin (Add * node){
        num++;
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<plus/>";
    }
    void visit_add_middle (Add * node){
        str += "";
    }
    void visit_add_end (Add * node) {
        int temp = num;
        str += "\n";
        while(temp-1 != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "</apply>";
    }


    void visit_sub_begin (Sub * node) {
        num++;
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<sub/>";
    }
    void visit_sub_middle (Sub * node){
        str += "";
    }
    void visit_sub_end (Sub * node) {
        int temp = num;
        str += "\n";
        while(temp-1 != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "</apply>";
    }


    void visit_mult_begin (Mult * node) {
        num++;
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<times/>";
    }
    void visit_mult_middle (Mult * node){
        str += "";
    }
    void visit_mult_end (Mult * node){
        int temp = num;
        str += "\n";
        while(temp-1 != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "</apply>";
    }


    void visit_div_begin (Div * node) {
        num++;
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<divide/>";
    }
    void visit_div_middle (Div * node) {
        str += "";
    }
    void visit_div_end (Div * node){
        int temp = num;
        str += "\n";
        while(temp-1 != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "</apply>";
    }


    void visit_pow_begin (Pow * node){
        num++;
        int temp = num;
        str += "\n";
        while(temp != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "<power/>";
    }
    void visit_pow_middle (Pow * node) {
        str += "";
    }
    void visit_pow_end (Pow * node) {
        int temp = num;
        str += "\n";
        while(temp-1 != 0)
        {
            str+= "  ";
            temp--;
        }
        str += "</apply>";
    }
    
    std::string PrintMath(Base* base)
    {
        return str + "\n  </apply>\n</math>";
    }

};

#endif


