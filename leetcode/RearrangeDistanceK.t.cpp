#include "gtest/gtest.h"
#include "RearrangeDistanceK.h"

TEST(RearrangeDistanceK, RearrangeDistanceK)
{
    RearrangeDistanceK sol;
    string s;
    int k = 0;
    string res;

    // test case 1
    s = "aabbcc";
    k = 3;
    res = sol.rearrangeString(s, k);
    cout << s << "->" << res << endl;
    EXPECT_FALSE(res.empty());

    // test case 2
    s = "aaabc";
    k = 3;
    res = sol.rearrangeString(s,k);
    cout << s << "->" << res << endl;
    EXPECT_TRUE(res.empty());

    // test case 3
    s = "aaadbbcc";
    k = 2;
    res = sol.rearrangeString(s,k);
    cout << s << "->" << res << endl;
    EXPECT_FALSE(res.empty());
}
