#include "gtest/gtest.h"
#include "GeneralizedAbbr.h"

TEST(GeneralizedAbbr, GeneralizedAbbr)
{
    GeneralizedAbbr sol;
    vector<string> res = sol.generateAbbreviations("word");
    EXPECT_EQ(16, res.size());
    // cout << res.size() << endl;
    // for(auto& w : res) {
    // cout << w << endl;
    //}
}
