#include "gtest/gtest.h"
#include "SparseMatrixMultiplication.h"

TEST(SparseMatrixMultiplication, SparseMatrixMultiplication)
{
    SparseMatrixMultiplication sol;
    vector<vector<int>> A;
    A.emplace_back(vector<int>{1,0,0});
    A.emplace_back(vector<int>{-1,0,3});
    vector<vector<int>> B;
    B.emplace_back(vector<int>{7,0,0});
    B.emplace_back(vector<int>{0,0,0});
    B.emplace_back(vector<int>{0,0,1});
    vector<vector<int>> res = sol.multiply(A, B);
    vector<vector<int>> target;
    target.emplace_back(vector<int>{7,0,0});
    target.emplace_back(vector<int>{-7,0,3});
    for(int i = 0; i < res.size(); ++i) {
        for(int j = 0; j < res[0].size(); ++j) {
            EXPECT_EQ(target[i][j], res[i][j]);
        }
    }
}
