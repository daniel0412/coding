/* 247 Strobogrammatic Number II
 * A strobogrammatic number is a number that looks the same when rotated 180
 *degrees (looked at upside down).
 *
 * Find all strobogrammatic numbers that are of length = n.
 *
 * For example,
 * Given n = 2, return ["11","69","88","96"].
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
#include <utility>

using namespace std;

class StrobogrammaticNumber2 {
  public:
    vector<string> findStrobogrammatic(int n)
    {
        buildMap();
        vector<string> res;
        string path(n, '0');
        find(res, n, path, 0);
        return res;
    }

  private:
    unordered_map<char, char> d_map;
    void buildMap()
    {
        d_map['0'] = '0';
        d_map['1'] = '1';
        d_map['6'] = '9';
        d_map['8'] = '8';
        d_map['9'] = '6';
    }

    void find(vector<string>& res, const int n, string& path, int id)
    {
        if(n == 0)
            return;
        if(id == n / 2) {
            if(n % 2 == 0) {
                res.push_back(path);
            }
            else {
                path[id] = '0';
                res.push_back(path);
                path[id] = '1';
                res.push_back(path);
                path[id] = '8';
                res.push_back(path);
            }
            return;
        }

        for(auto kv : d_map) {
            if(id == 0 && kv.first == '0')
                continue;
            path[id] = kv.first;
            path[n - id - 1] = kv.second;
            find(res, n, path, id + 1);
        }
    }
};
