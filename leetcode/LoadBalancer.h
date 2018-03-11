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

class LoadBalancer {
  public:
    // define 'Cluster' struture, which stores load/machines/avgLoad
    // information
    struct Cluster {
        Cluster(int loads, int machines) : d_loads(loads), d_machines(machines)
        {
            d_avgLoads = d_loads / d_machines;
        }
        void increaseMachineByOne()
        {
            ++d_machines;
            d_avgLoads = d_loads / d_machines;
        }
        int d_loads;
        int d_machines;
        int d_avgLoads;
    };

    int loadbalancer(const vector<int> loads, int B)
    {
        int n = loads.size();
        // if number of cluster is greater than total number of machines
        // task on some cluster cannot be processed
        if(n > B)
            return numeric_limits<int>::max();
        // define comparator for 'Cluster' class
        auto comp = [](const Cluster& a, const Cluster& b) {
            return a.d_avgLoads < b.d_avgLoads;
        };

        // first assume each cluster has one machines, and put all cluster
        // information into
        // max heap, sorted by average loads
        prioirty_queue<Cluster, vector<Cluster>, decltype(comp)> pq(comp);
        for(size_t i = 0; i < n; ++i) {
            pq.emplace(Cluster(loads[i], 1));
        }
        B -= n;

        // before the machine resources are used up,
        // always add one machine to the top cluster in the max heap, which has
        // the largest load
        while(B-- > 0) {
            auto tmp = pq.top();
            pq.pop();
            tmp.increaseMachineByOne();
            pq.emplace(tmp);
        }
        // the final max avg load is from the top of the max heap
        return pq.top().d_avgLoads;
    }

  private:
};
