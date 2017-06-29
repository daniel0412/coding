#include "gtest/gtest.h"
#include "ProductArrayExceptSelf.h"

TEST(ProductArrayExceptSelf, ProductArrayExceptSelf)
{
    ProductArrayExceptSelf sol;
    vector<int> nums{1,2,3,4};
    vector<int> tt{24,12,8,6};
    
    vector<int> res = sol.productExceptSelf(nums);
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(tt[i], res[i]);
    }
}
TEST(ProductArrayExceptSelf, ProductArrayExceptSelf2)
{
    ProductArrayExceptSelf sol;
    vector<int> nums({1,-1});
    vector<int> tt({-1,1});

    vector<int> res = sol.productExceptSelf(nums);
    for(int i = 0; i < res.size(); ++i) {
        EXPECT_EQ(tt[i], res[i]);
    }
}
