#include "gtest/gtest.h"
#include "LetterCombination.h"

TEST(LetterCombination, LetterCombination)
{
    LetterCombination sol;
    string digits("73");
    vector<string> res = sol.letterCombinations(digits);
    for(auto& s : res) {
        cout << s << endl;
    }

}
