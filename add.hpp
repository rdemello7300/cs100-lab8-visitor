#ifndef __ADD_HPP__
#define __ADD_HPP__
#include "base.hpp"

class Add : public Base {
    private:
	    Base* num1;
        Base* num2;
    public:
        Add(Base* value1, Base* value2) : num1(value1), num2(value2) {}

    double evaluate() { return num1 -> evaluate() + num2 -> evaluate(); }
        virtual std::string stringify() { return "("+ num1 -> stringify()+ " + "+ num2 -> stringify()+")"; }
        int number_of_children()
        {
            return num1 -> number_of_children() + num2 -> number_of_children();
        }
        Base* get_child(int i)
        {
            if(i == 0) return num1;
            else if(i == 1) return num2;
            else return NULL;
        }
};
#endif