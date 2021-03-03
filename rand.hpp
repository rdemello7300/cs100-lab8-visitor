#ifndef __RAND_HPP__
#define __RAND_HPP__

#include "base.hpp"
using namespace std;
#include<time.h>
#include <string>
#include <iostream>
#include <stdio.h>
#include "visitor.hpp"

class Rand : public Base {
    private:
        double num;
    public:
        Rand() : num(rand() % 100) { }
        double evaluate() { return num; }
        std::string stringify() { return to_string(num); }
	int number_of_children() { return 0; }
        Base* get_child(int i) { return this; }
	void accept(Visitor* visitor, int index) 
        {
            if(index == 0) visitor -> visit_add_begin(this);
            else if(index == 1) visitor -> visit_add_middle(this);
            else visitor -> visit_add_end(this);
        }
};

#endif
