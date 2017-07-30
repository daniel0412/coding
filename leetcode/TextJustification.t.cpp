#include "gtest/gtest.h"
#include "TextJustification.h"

TEST(TextJustification, TextJustification)
{
    TextJustification sol;
    vector<string> words = {
        "This", "is", "an", "example", "of", "text", "justification."};
    int maxWidth = 16;
    vector<string> res = sol.fullJustify(words, maxWidth);
    vector<string> target = {
        "This    is    an", "example  of text", "justification.  "};
    ASSERT_EQ(res.size(), target.size());
    for(int i = 0; i < target.size(); ++i) {
        ASSERT_EQ(res[i], target[i]);
    }
    for(auto& r : res) {
        cout << "|" << r << "|" << endl;
    }
}

TEST(TextJustification, TextJustification2)
{
    TextJustification sol;
    vector<string> words = {
        "Imagination", "is", "more", "important", "than", "knowledge."};
    int maxWidth = 14;
    vector<string> res = sol.fullJustify(words, maxWidth);
    vector<string> target = {"Imagination is",
                             "more important",
                             "than          ",
                             "knowledge.    "};

    for(int i = 0; i < target.size(); ++i) {
        ASSERT_EQ(res[i], target[i]);
    }
    for(auto& r : res) {
        cout << "|" << r << "|" << endl;
    }
}
