#include "gtest/gtest.h"
#include "GenParenthesis.h"

TEST(GenParenthesis, GenParenthesis)
{
    GenParenthesis sol;
    int n = 4;
    vector<string> res = sol.generateParenthesis(n);
    for(auto s : res) {
        cout << s << endl;
    }
}
