/*
 * An abbreviation of a word follows the form <first letter><number><last
 *letter>. Below are some examples of word abbreviations:
 *
 * a) it                      --> it    (no abbreviation)
 *
 *      1
 *      b) d|o|g                   --> d1g
 *
 *                    1    1  1
 *                         1---5----0----5--8
 *                         c) i|nternationalizatio|n  --> i18n
 *
 *                                       1
 *                                            1---5----0
 *                                            d) l|ocalizatio|n          -->
 *l10n
 *                                            Assume you have a dictionary and
 *given a word, find whether its abbreviation is unique in the dictionary. A
 *word's abbreviation is unique if no other word from the dictionary has the
 *same abbreviation.
 *
 *                                            Example:
 *
 *                                            Given dictionary = [ "deer",
 *"door", "cake", "card" ]
 *
 *                                            isUnique("dear") -> false
 *                                            isUnique("cart") -> true
 *                                            isUnique("cane") -> false
 *                                            isUnique("make") -> true
 */

#include <string>
#include <vector>
#include <list>
#include <stack>
#include <sstream>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>
#include <algorithm>
#include <utility>
#include "utils.h"

using namespace std;

class UniqWordAbbr {
  public:
    UniqWordAbbr(const vector<string>& dict)
    {
        for(const auto& s : dict) {
            string formated = format(s);
            unordered_map<string, string>::iterator iter =
                d_map.find(formated);
            if(iter != d_map.end() && iter->second != s)
                iter->second = "";
            else
                d_map[formated] = s;
        }
    }
    bool isUniqe(const string& word)
    {
        unordered_map<string, string>::iterator iter =
            d_map.find(format(word));
        return iter == d_map.end() || iter->second == word;
    }

  private:
    string format(const string& s)
    {
        if(s.size() <= 2)
            return s;
        return s.front() + to_string(s.size()) + s.back();
    }
    unordered_map<string, string> d_map;
};
