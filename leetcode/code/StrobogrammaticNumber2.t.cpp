#include "gtest/gtest.h"
#include "StrobogrammaticNumber2.h"

TEST(StrobogrammaticNumber2, StrobogrammaticNumber2)
{
    StrobogrammaticNumber2 sol;

    vector<string> res;
    unordered_set<string> resSet;

    int n = 0;
    res = sol.findStrobogrammatic(n);
    EXPECT_EQ(0, res.size());

    n = 1;
    res = sol.findStrobogrammatic(n);
    EXPECT_EQ(3, res.size());
    resSet.clear();
    resSet.insert(res.begin(), res.end());
    EXPECT_EQ(resSet.count("0"), 1);
    EXPECT_EQ(resSet.count("1"), 1);
    EXPECT_EQ(resSet.count("8"), 1);

    n = 2;
    res = sol.findStrobogrammatic(n);
    EXPECT_EQ(4, res.size());
    resSet.clear();
    resSet.insert(res.begin(), res.end());
    EXPECT_EQ(resSet.count("11"), 1);
    EXPECT_EQ(resSet.count("69"), 1);
    EXPECT_EQ(resSet.count("96"), 1);
    EXPECT_EQ(resSet.count("88"), 1);

    n = 3;
    res = sol.findStrobogrammatic(n);
    EXPECT_EQ(12, res.size());
    resSet.clear();
    resSet.insert(res.begin(), res.end());
    EXPECT_EQ(resSet.count("101"), 1);
    EXPECT_EQ(resSet.count("111"), 1);
    EXPECT_EQ(resSet.count("181"), 1);
    EXPECT_EQ(resSet.count("609"), 1);
    EXPECT_EQ(resSet.count("619"), 1);
    EXPECT_EQ(resSet.count("689"), 1);
    EXPECT_EQ(resSet.count("808"), 1);
    EXPECT_EQ(resSet.count("818"), 1);
    EXPECT_EQ(resSet.count("888"), 1);
    EXPECT_EQ(resSet.count("906"), 1);
    EXPECT_EQ(resSet.count("916"), 1);
    EXPECT_EQ(resSet.count("986"), 1);

    n = 4;
    res = sol.findStrobogrammatic(n);
    EXPECT_EQ(20, res.size());
    resSet.clear();
    resSet.insert(res.begin(), res.end());
}
