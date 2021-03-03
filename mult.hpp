#ifndef __MULT_HPP__
#define __MULT_HPP__

#include "base.hpp"

class Mult : public Base {
    private:
	    Base* num1;
        Base* num2;
    public:
        Mult(Base* value1, Base* value2) : num1(value1), num2(value2){}
	double evaluate() { return num1 -> evaluate() * num2 -> evaluate(); }
        std::string stringify() { return "("+ num1 -> stringify()+ " * "+ num2 -> stringify()+")"; }
        int number_of_children()
        {
            int left = num1 -> number_of_children();
            int right = num2 -> number_of_children();
            if(left == 0 )left++;
            if(right == 0) right++;
            return left + right;
        }
        Base* get_child(int i)
        {
            if(i == 0) return num1;
            else if(i == 1) return num2;
            else return NULL;
        }
        void accept(Visitor* visitor, int index)
        {
            if (index == 0)
                visitor -> visit_mult_begin(this);
            else if (index == 1)
                visitor -> visit_mult_middle(this);
            else if (index == 2)
                visitor -> visit_mult_end(this);
        }
};
#endif
