#include "include/mathparser.h"

namespace Serf
{
Operation::Operation(char value) : precedence([value]{
                                    if(value == '*' || value == '/'){
                                        return 2;
                                    }else {
                                        return 1;
                                    } }()),
                                        _op(value) {}



int Operation::Evaluate() const {
    if (_op == '*'){
        return _left->Evaluate() * _right->Evaluate();
    }else if (_op == '+'){
        return _left->Evaluate() + _right->Evaluate();
    }else if (_op == '-'){
        return _left->Evaluate() - _right->Evaluate();
    }else if (_op == '/'){
        if (_right->Evaluate() == 0){            
            return 0;
        }
        return _left->Evaluate() / _right->Evaluate();
    }
    return 0;
}

void Operation::SetLeft(std::shared_ptr<Node> node) { _left = node; }
void Operation::SetRight(std::shared_ptr<Node> node) { _right = node; }

}


