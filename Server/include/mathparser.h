
#pragma once
#include <iostream>
#include <memory>
#include <stack>
#include <string>

namespace Serf
{

    struct Node
    {
    public:
        virtual int Evaluate() const = 0;
    };

    class Value : public Node
    {
    public:
        Value(char digit) : _value(digit - '0') {}
        int Evaluate() const override { return _value; }

    private:
        const int _value;
    };


    class Operation : public Node
    {
    public:
        Operation(char value);

        const int precedence;

        int Evaluate() const override ;

        void SetLeft(std::shared_ptr<Node> node);
        void SetRight(std::shared_ptr<Node> node);
        bool GetFlagDivisionZero(){return flagZero;}

    private:
        const char _op;
        bool flagZero;
        std::shared_ptr<const Node> _left, _right;
    };

    class mathparse {
    public:
    template <class Iterator>
    std::shared_ptr<Node> Parse(Iterator token, Iterator end);        

    };

    template <class Iterator>
    std::shared_ptr<Node> mathparse::Parse(Iterator token, Iterator end){
        if (token == end){
            return std::make_shared<Value>('0');
        }

        std::stack<std::shared_ptr<Node>> values;
        std::stack<std::shared_ptr<Operation>> ops;

        auto PopOps = [&](int precedence){
            while (!ops.empty() && ops.top()->precedence >= precedence){
                auto value1 = values.top();
                values.pop();
                auto value2 = values.top();
                values.pop();
                auto op = ops.top();
                ops.pop();

                op->SetRight(value1);
                op->SetLeft(value2);

                values.push(op);
            }
        };

        while (token != end){
            const auto &value = *token;
            if (value >= '0' && value <= '9'){
                values.push(std::make_shared<Value>(value));
            }else if (value == '*' || value == '/'){
                PopOps(2);
                ops.push(std::make_shared<Operation>(value));
            }else if (value == '+' || value == '-'){
                PopOps(1);
                ops.push(std::make_shared<Operation>(value));
            }

            ++token;
        }

        while (!ops.empty()){
            PopOps(0);
        }

        return values.top();
    }
}
