#include "gtest/gtest.h"
#include "WordSquares.h"

TEST(WordSquares, TestTrie)
{
    vector<string> dict = {"ab", "abc", "acd", "abcdef", "hello", "hea"};
    Trie myTrie;
    myTrie.buildTrie(dict);
    vector<string> words;
    myTrie.getAllWordsInTrie(words);
    unordered_set<string> resultSet(words.begin(), words.end());
    EXPECT_EQ(resultSet.size(), 6);
    for(const auto& w : words)
        EXPECT_EQ(resultSet.count(w), 1);

    words.clear();
    resultSet.clear();
    vector<char> prefix = {'a', 'b'};
    words.push_back("ab");
    words.push_back("abc");
    words.push_back("abcdef");

    myTrie.findAllWordsWithPrefix(resultSet, prefix);
    for(const auto& w : words)
        EXPECT_EQ(resultSet.count(w), 1);
}

TEST(WordSquares, WordSquares1)
{
    vector<string> givenWords = {"area", "lead", "wall", "lady", "ball"};
    vector<vector<string> > res;
    WordSquares sol;
    res = sol.wordSquares(givenWords);
    EXPECT_EQ(res.size(), 2);

    cout << "++++++++++++++++++++++++" << endl;
    cout << "constructed word squares" << endl;
    for(const auto& vec : res) {
        for(const auto& w : vec) {
            cout << w << "|";
        }
        cout << endl;
    }
    cout << "++++++++++++++++++++++++" << endl;
}

TEST(WordSquares, WordSquares2)
{
    vector<string> givenWords = {"abat", "baba", "atan", "atal"};
    vector<vector<string> > res;
    WordSquares sol;
    res = sol.wordSquares(givenWords);
    EXPECT_EQ(res.size(), 2);

    cout << "++++++++++++++++++++++++" << endl;
    cout << "constructed word squares" << endl;
    for(const auto& vec : res) {
        for(const auto& w : vec) {
            cout << w << "|";
        }
        cout << endl;
    }
    cout << "++++++++++++++++++++++++" << endl;
}
