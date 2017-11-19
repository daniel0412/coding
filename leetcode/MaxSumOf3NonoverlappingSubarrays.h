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

class MaxSumOf3NonoverlappingSubarrays {
  public:
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k)
    {
        int n = nums.size();
        if(n < 3 * k)
            return vector<int>();

        // calculate pre-sum
        vector<int> sums(n, 0);
        sums[0] = nums.front();
        for(int i = 1; i < n; ++i) {
            sums[i] = sums[i - 1] + nums[i];
        }


        // calculate max sum starting index for left subarray within [0, i]
        vector<int> posLeft(n, 0);
        int maxS = sums[k - 1];
        for(int i = 1; i <= n - 3 * k; ++i) {
            int diff = sums[i + k - 1] - sums[i - 1];
            if(diff > maxS) {
                maxS = diff;
                posLeft[i + k - 1] = i;
            }
            else {
                posLeft[i + k - 1] = posLeft[i + k - 2];
            }
        }

        vector<int> posRight(n, 0);
        maxS = sums[n - 1] - sums[n - 1 - k];
        posRight[n - k] = n - k;
        for(int i = n - k - 1; i >= 2 * k; --i) {
            int diff = sums[i + k - 1] - sums[i - 1];
            if(diff >= maxS) {
                posRight[i] = i;
                maxS = diff;
            }
            else {
                posRight[i] = posRight[i + 1];
            }
        }

        // traverse all the mid subarrays
        vector<int> res(3, 0);
        maxS = numeric_limits<int>::min();
        for(int i = k; i <= n - 2 * k; ++i) {
            int l = posLeft[i - 1], r = posRight[i + k];
            int midSum = sums[i + k - 1] - sums[i - 1];
            int leftSum =
                (l == 0) ? sums[k - 1] : (sums[l + k - 1] - sums[l - 1]);
            int rightSum = sums[r + k - 1] - sums[r - 1];
            curSum = midSum + leftSum + rightSum;
            if(curSum > maxS) {
                maxS = curSum;
                res[0] = l;
                res[1] = i;
                res[2] = r;
            }
        }

        return res;
    }
}
}
}
}
}
}
}
}
}

private:
}
;
