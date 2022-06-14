#include "solution.h"
#include "util.h"
#include <unordered_set>
#include <numeric>
#include <iterator>
#include <unordered_map>
#include <deque>
#include <string>
#include <sstream>
#include <algorithm>
#include <stack>
#include <functional>
using namespace sol133;
using namespace std;

/*takeaways
  - we are detecting if there is any cycle in the
    graph
  - topological sort plus DFS to detect cycles
  - 0 -> 1 -> 2 -> 0
    - during the DFS traversal, we mark everyone as "visiting"
      not marked as "visited" before. The nodes that are marked as
      "visited" means they have been visited by other paths, so we
       can just ignore them. If we ever re-visit a "visiting" node then we
      know there is a cycle in the path
    - we visit the 0 more than once during the same DFS visit
      - there is a cycle

  - time complexity O(n)
    - the edges are less than the vertexes most likely O(V+E) -> O(V)

*/

bool Solution::canFinish(int numCourses, vector<pair<int, int>> &prerequisites)
{
  auto g = vector<vector<int>>(numCourses);
  for (auto p : prerequisites)
    /*  you need to take p.second before you can take p.first
       - so in the graph, there is a unidirectional edge from
         p.second to p.first
    */
    g[p.second].push_back(p.first);

  auto visit = vector<int>(numCourses, 0);

  for (auto i = 0; i < numCourses; i++)
  {
    if (_detect(i, visit, g))
      return false;
  }

  return true;
}

bool Solution::_detect(int n, vector<int> &v, vector<vector<int>> &g)
{
  /* visiting - a cycle is detected */
  if (v[n] == 1)
    return true;
  /* visited - there are other paths to get to this node */
  if (v[n] == 2)
    return false;
  /* visiting */
  v[n] = 1;

  for (auto node : g[n])
    if (_detect(node, v, g))
      return true;

  /* visited */
  v[n] = 2;
  return false;
}