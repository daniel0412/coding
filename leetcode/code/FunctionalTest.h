/*
 *
 */

#include <string>
#include <vector>
#include <stack>
#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <queue>
#include <functional>

using namespace std;

class FunctionalTest {
  public:
      int testFunctional(int (*f)(int), int x) {
          return (*f)(x);
      }

  private:
};
