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

class EncodeDecodeTineyURL {
  public:
    // Encodes a URL to a shortened URL.
    string encode(string longUrl)
    {
        const string prefix("http://tinyurl.com/");
        string dict = buildDict();
        if(d_long2short.count(longUrl)) {
            return prefix + d_long2short[longUrl];
        }
        string suffix;
        int dictSize = dict.size();
        for(int i = 0; i < 6; ++i) {
            suffix.push_back(dict[rand() % dictSize]);
        }
        int id = 0;
        while(d_short2long.count(suffix)) {
            suffix[id % 6] = dict[rand() % dictSize];
            ++id;
        }
        string res = prefix + suffix;
        d_long2short[longUrl] = suffix;
        d_short2long[suffix] = longUrl;
        return suffix;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl)
    {
        string suffix = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return d_short2long.count(suffix) ? d_short2long[suffix] : shortUrl;
    }

  private:
    string buildDict()
    {
        string dict;
        for(char c = '0'; c <= '9'; ++c)
            dict.push_back(c);
        int diff = 'A' - 'a';
        for(char c = 'a'; c <= 'z'; ++c) {
            dict.push_back(c);
            dict.push_back(c + diff);
        }
        return dict;
    }
    unordered_map<string, string> d_short2long;
    unordered_map<string, string> d_long2short;
};
