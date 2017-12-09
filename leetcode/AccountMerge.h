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

class AccountMerge {
  public:
    vector<vector<string> > accountsMerge(vector<vector<string> >& accounts)
    {
    }

  private:
    vector<vector<string> > bfs(vector<vector<string> >& accounts)
    {
        unordered_map<string, vector<int> > nameToIds;
        for(int id = 0; id < acconts.size(); ++id) {
            for(int i = 1; i < accounts[id].size(); ++i) {
                nameToIds[accounts[id][i]].emplace_back(id);
            }
        }
        vector<vector<string> > res;
        queue<int> q;
        vector<bool> visited(accounts.size(), false);
        for(int id = 0; id < accounts.size(); ++id) {
            if(visited[id])
                continue;
            q.push(id);
            visited[id] = true;
            set<string> tmp;
            string name = accounts[id][0];
            while(!q.empty()) {
                int curId = q.top();
                q.pop();
                for(int i = 1; i < accounts[curId].size(); ++i) {
                    tmp.insert(accounts[curId][i]);
                    for(auto& ii : nameToIds[accounts[curId][i]]) {
                        if(visited[ii])
                            continue;
                        q.push(ii);
                        visited[ii] = true;
                    }
                }
            }
            res.emplace_back(vector<string>{name});
            copy(tmp.begin(), tmp.end(), back_inserter(res.back()));
        }
        return res;
    }
};
