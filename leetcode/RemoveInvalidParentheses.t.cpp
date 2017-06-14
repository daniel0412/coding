#include "gtest/gtest.h"
#include "RemoveInvalidParentheses.h"

TEST(RemoveInvalidParentheses, RemoveInvalidParentheses)
{
    RemoveInvalidParentheses sol;
    string s("()())()");
    vector<string> res = sol.removeInvalidParentheses(s);
    cout << res.size() << endl;
    for(auto& ss : res) {
        cout << ss << endl;
    }
}
