#ifndef OP_HPP
#define OP_HPP

#include "base.hpp"
#include "visitor.hpp"
#include <string>
#include <iostream>
#include <stdio.h>

class Op: public Base{
   private:
	double num;
   public:
	Op() : num(0) { }
	Op(double value) : num(value) { }
        double evaluate() { return num; }
        std::string stringify() {
	 return std::to_string(num); }
	int number_of_children(){return 0;}
	Base* get_child(int i) { return NULL; }
    void accept(Visitor* visitor, int index)
    {
        visitor -> visit_op(this);
    }
};

#endif //OP_HPP
