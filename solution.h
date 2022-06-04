
#ifndef SOLUTION_H
#define SOLUTION_H

#include "node.h"
#include <vector>
#include <queue>
#include <unordered_map>
#include <map>
#include <string>
#include <stack>

using namespace std;
namespace sol133
{

  class Solution
  {
  private:
    bool _detect(int n, vector<int> &v, vector<vector<int>> &g);

  public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites);
  };
}
#endif