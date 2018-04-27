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

class SequenceReconstruction {
  public:
    bool sequenceReconstruction(vector<int>& org, vector<vector<int> >& seqs)
    {
        unordered_map<int, size_t> m, pre;
        for(int i = 0; i < org.size(); ++i)
            m[org[i]] = i;
        for(const auto& s : seqs) {
            for(int i = 0; i < s.size(); ++i) {
                // number not in the ori seq
                if(m.count[s[i]] == 0)
                    return false;
                // seq order violates orig order
                if(i > 0 && m[s[i - 1]] > m[s[i]])
                    return false;
                // get the index of the previous element
                if(pre.count(s[i]) == 0) {
                    pre[s[i]] = i > 0 ? m[s[i - 1]] : -1;
                }
                else {
                    pre[s[i]] = max(pre[s[i]], i > 0 ? m[s[i - 1]] : -1);
                }
            }
        }
        for(int i = 0; i < org.size(); ++i) {
            if(pre[org[i]] != i - 1)
                return false;
        }
        return true;
    }

  private:
};
