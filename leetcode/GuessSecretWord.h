/*
 *
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class GuessSecretWord {
  public:
    /* how to minimize the call of the given api ?? */


    /* for each word in dict
           * we can get how many same chars between all other words and given
     * word
           * maintain a list of these information. e.g., given w, S0 (o char
     * common): (w1, w2), S1 (1 char common): (w3, w4), ...
           * Worst case: secrect always falls into the longest list
           * so to minimize all possible tries
           * from all the longest list for each word, we choose to start from
     * the minimum longest word
           * In this sense, this is a MIN-MAX problem
           */

    string guessWord(unordered_set<string>& dict)
    {
        while(!dict.empty()) {
            // find a random one to try
            string curWord = *dict.begin();
            int num = numSimToSecret(curWord);
            // if all chars in secret, bingo (??? all char exists != sequence
            // the same)
            if(num == curWord.size())
                return curWord;
            // remove those words that have different same chars with guessed
            // word
            dict.erase(curWord);

            for(auto iter = dict.begin(); iter != dict.end();) {
                if(countSimilarity(w, curWord) != num) {
                    iter = dict.erase(*iter);
                }
                ++iter;
            }
        }
        return "";
    }

    string guessWord(unordered_set<string>& dict)
    {
        if(dict.empty())
            return "";
        string curWord = *dict.begin();
        int num = numSimToSecret(curWord);
        if(num == curWord.size())
            return curWord;
        dict.erase(curWord);
        for(auto iter = dict.begin(); iter != dict.end();) {
            if(countSimilarity(w, curWord) != num) {
                iter = dict.erase(*iter);
            }
            ++iter;
        }
        return guessWord(dict);
    }

    int countSimilarity(const string& w1, const string& w2)
    {
        unorder_map<char, int> m;
        for(auto c : w1) {
            ++m[c];
        }
        int cnt = 0;
        for(auto c : w2) {
            if(m.count(c)) {
                ++cnt;
                if(--m[c] == 0)
                    m.erase(c);
            }
        }
        return cnt;
    }

  private:
    // given api
    // return number of same chars between w and secret word
    int numSimToSecret(const string& w)
    {
        int k = 0;
        return k;
    }
};
