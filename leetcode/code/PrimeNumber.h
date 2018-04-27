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

class PrimeNumber {
  public:
    PrimeNumber(int maxNumber) : d_max(maxNumber), d_currentNum(1) {}
    int getNextPrimeNumber()
    {
        while(++d_currentNum <= d_max) {
            if(isPrime(d_currentNum))
                return d_currentNum;
        }
        return -1;
    }

    // Sieve of Eratosthenes implementation
    vector<int> getAllPrimesUpTo(int n)
    {
        if(n < 2)
            return {};
        vector<bool> isPrimeNum(n + 1, true);
        isPrimeNum[0] = false;
        isPrimeNum[1] = false;
        for(int i = 2; i <= sqrt(n); ++i) {
            if(isPrimeNum[i]) {
                // only need to start from i*i, since any multiplier less than i is done
                // increse j by i, is to test all multipliers
                for(int j = i * i; j <= n; j += i) {
                    isPrimeNum[j] = false;
                }
            }
        }
        vector<int> res;
        for(int i = 2; i <= n; ++i) {
            if(isPrimeNum[i])
                res.push_back(i);
        }
        return res;
    }

  private:
    // heuristics with prunning, not up to n
    bool isPrime(const int n)
    {
        // only need to check from 2 up to sqrt(n)
        for(int i = 2; i <= sqrt(n); ++i) {
            if(n % i == 0)
                return false;
        }
        return true;
    }

    int d_max;
    int d_currentNum;
};

// TESTS:
// 1. negative number
// 2. within the range
// 3. beyond the range
// 4. on the boundary

int main()
{
    int n = 100;
    PrimeNumber generator(n);
    vector<int> res = generator.getAllPrimesUpTo(n);
    cout << res.size() << " primes under " << n << endl;
    for(auto p : res)
        cout << p << " ";
    cout << endl;
    while(1) {
        int p = generator.getNextPrimeNumber();
        if(p == -1)
            break;
        cout << p << " ";
    }
    return 0;
}
