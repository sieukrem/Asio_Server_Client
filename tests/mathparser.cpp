#include "../Server/include/mathparser.h"

#include <string>
#include <gtest/gtest.h>

TEST(MathParser, Sum_of_2_operands) {
    Serf::mathparser testee;
    std::string expression = "1+2";

    auto result = testee.Parse(expression.begin(), expression.end())->Evaluate();

    EXPECT_EQ(3,result);
}

TEST(MathParser, Div_of_2_operands) {
    Serf::mathparser testee;
    std::string expression = "4/2";

    auto result = testee.Parse(expression.begin(), expression.end())->Evaluate();

    EXPECT_EQ(2,result);
}

TEST(MathParser, Sum_supports_expressions_with_empty_spaces) {
    Serf::mathparser testee;
    std::string expression = " 4 + 2  ";

    auto result = testee.Parse(expression.begin(), expression.end())->Evaluate();

    EXPECT_EQ(6,result);
}


TEST(MathParser, Mul_before_Sum) {
    Serf::mathparser testee;
    std::string expression = " 4 * 2 + 2  ";

    auto result = testee.Parse(expression.begin(), expression.end())->Evaluate();

    EXPECT_EQ(10,result);
}