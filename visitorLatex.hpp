#ifndef __VISITOR_LATEX_HPP__
#define __VISITOR_LATEX_HPP__

#include "iterator.hpp"
#include "visitor.hpp"
#include "op.hpp"
#include "mult.hpp"
#include "add.hpp"
#include "sub.hpp"
#include "pow.hpp"
#include "rand.hpp"
#include "div.hpp"

class VisitorLaTeX : public Visitor{
    protected:
        std::string str = "";
    public:
        virtual void visit_op(Op* node);
        virtual void visit_rand(Rand* node);
        virtual void visit_add_begin(Add* node) { str += "{("; }
        virtual void visit_add_middle(Add* node) { str += "+"; }
        virtual void visit_add_end(Add* node) { str += ")}"; }
        virtual void visit_sub_begin(Sub* node) { str += "{("; }
        virtual void visit_sub_middle(Sub* node) { str += "-"; }
        virtual void visit_sub_end(Sub* node) { str += ")}"; }
        virtual void visit_mult_begin(Mult* node) { str += "{("; }
        virtual void visit_mult_middle(Mult* node) { str += "\\cdot"; }
        virtual void visit_mult_end(Mult* node) { str += ")}"; }
        virtual void visit_div_begin(Div* node) { str += "{\\frac"; }
        virtual void visit_div_middle(Div* node) { str += ""; }
        virtual void visit_div_end(Div* node) { str += "}"; }
        virtual void visit_pow_begin(Pow* node) { str += "{("; }
        virtual void visit_pow_middle(Pow* node) { str += "^"; }
        virtual void visit_pow_end(Pow* node) { str += ")}"; }
        std::string PrintLaTeX(Base* ptr) { return "$" + str + "$"; }
};

void VisitorLaTeX::visit_op(Op* node)
{
    str += "{" + node -> stringify() + "}";
}

void VisitorLaTeX::visit_rand(Rand* node)
{
    str += "{" + node -> stringify() + "}";
}

#endif

