#ifndef __SUB_HPP__
#define __SUB_HPP__

#include "base.hpp"

class Sub : public Base {
    private:
	    Base* num1;
        Base* num2;
    public:
        Sub(Base* value1, Base* value2) : num1(value1), num2(value2){}
	double evaluate() { return num1 -> evaluate() - num2 -> evaluate(); }
        virtual std::string stringify() { return "(" + num1 -> stringify() +" - "+ num2 -> stringify() +")"; }
        int number_of_children()
        {
            return 2;
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
                visitor -> visit_sub_begin(this);
            else if (index == 1)
                visitor -> visit_sub_middle(this);
            else if (index == 2)
                visitor -> visit_sub_end(this);
        }
};
#endif
