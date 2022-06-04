#include <iostream>
#include <vector>
#include <string>
#include <tuple>
#include <unordered_map>
#include "solution.h"
#include "util.h"

using namespace std;
using namespace sol133;

/*
Input: 2, [[1,0]]
Output: true
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0.
             So it is possible.
*/

tuple<int, vector<pair<int, int>>, bool>
testFixture1()
{
  auto pre = vector<pair<int, int>>{
      {1, 0}};

  return make_tuple(2, pre, true);
}

/*
Input: 2, [[1,0],[0,1]]
Output: false
Explanation: There are a total of 2 courses to take.
             To take course 1 you should have finished course 0, and to take course 0 you should
             also have finished course 1. So it is impossible.
*/

tuple<int, vector<pair<int, int>>, bool>
testFixture2()
{
  auto pre = vector<pair<int, int>>{
      {1, 0}, {0, 1}};

  return make_tuple(2, pre, false);
}

void test1()
{
  auto f = testFixture1();
  Solution sol;
  cout << "Expect to see: " << get<2>(f) << endl;
  cout << sol.canFinish(get<0>(f), get<1>(f)) << endl;
}

void test2()
{
  auto f = testFixture2();
  Solution sol;
  cout << "Expect to see: " << get<2>(f) << endl;
  cout << sol.canFinish(get<0>(f), get<1>(f)) << endl;
}

main()
{
  test1();
  test2();
  return 0;
}