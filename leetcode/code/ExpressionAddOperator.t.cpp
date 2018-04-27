#include "gtest/gtest.h"
#include "ExpressionAddOperator.h"

TEST(ExpressionAddOperator, ExpressionAddOperator)
{
    ExpressionAddOperator sol;
    vector<string> res = sol.addOperators("00232", 8);
    for(auto& r : res)
        cout << r << endl;
}
