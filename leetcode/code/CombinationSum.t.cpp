#include "gtest/gtest.h"
#include "CombinationSum.h"

TEST(CombinationSum, CombinationSum)
{
    CombinationSum sol;
    vector<int> candidates={2,3,6,7};
    int target = 7;
    vector<vector<int>> res = sol.combinationSum(candidates, target);
    for(auto v:res) {
        for(auto d:v) {
            cout << d << " ";
        }
        cout << endl;
    }
}
