// https://icpcarchive.ecs.baylor.edu/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=1821
#include <bits/stdc++.h>

using namespace std;

inline int lowest_common_ancestor(vector<int> &match, vector<int> &flower,
                                  vector<int> &parent, int a, int b) {
  static vector<int> visited;
  static int visit = 0;
  if (visited.size() < match.size()) visited.resize(match.size());
  ++visit;
  // visit = 2
  // 0 - 1 - 1    0 - 1 - 2    0 - 1 - 2    0 - 2 - 2
  //     | /   ->     |     ->     |     ->     |
  //     0            0            2            2
  for (; visited[a] != visit; swap(a, b)) {
    if (!a) continue;
    visited[a] = visit;
    a = flower[parent[match[a]]];
  }
  return a;
}

bool augment(vector<vector<int>> &graph, vector<int> &match,
             vector<int> &status, vector<int> &parent, const int state,
             const int root) {
  //  Flowers are only meaningful to the newly added node(current root)
  vector<int> flower(graph.size());
  for (int i = 0; i < flower.size(); ++i) flower[i] = i;

  status[root] = state;
  parent[root] = 0;
  queue<int> que;  // only even nodes are allowed
  que.push(root);
  // To calculate the correct even/odd label, BFS is applied instead of DFS
  while (que.size()) {
    const auto node = que.front();
    que.pop();
    for (const auto &x : graph[node]) {
      if (status[x] < state) {  // not visited
        if (!match[x]) {        // found augmenting path
          // Before: 0, 1 <-> 2, 3 <-> 4, 5
          // After: 0 <-> 1, 2 <-> 3, 4 <-> 5
          for (auto new_odd = node, new_even = x, old_odd = -2; old_odd;
               new_odd = parent[old_odd], new_even = old_odd) {
            old_odd = match[new_odd];
            match[new_odd] = new_even;
            match[new_even] = new_odd;
          }
          return true;
        }
        // matched odd node not visited with current root
        parent[x] = node;
        status[x] = state + 1;
        status[match[x]] = state;
        que.push(match[x]);
      } else if (status[x] == state &&
                 flower[node] != flower[x]) {  // new flower, node and child are
                                               // both even nodes
        const auto flower_root =
            lowest_common_ancestor(match, flower, parent, node, x);
        // Update the parent labels inside a flower. The parent labels should be
        // like the following image to ensure correctness when updating matching
        // nodes after a new augmenting path is found
        // https://jacky860226.github.io/general-graph-weighted-match-slides/img/pa_set.png
        for (int i = 0, even_node = flower[x], new_parent = flower[node]; i < 2;
             ++i, even_node = flower[node], new_parent = flower[x]) {
          while (flower[even_node] != flower_root) {
            parent[even_node] = new_parent;
            // All nodes in a flower should be even
            // May pass through previous flowers where the nodes are even
            // already
            if (status[new_parent = match[even_node]] == state + 1) {
              status[new_parent] = state;
              que.push(new_parent);
            }
            flower[even_node] = flower[new_parent] = flower_root;
            even_node = parent[new_parent];
          }
        }
      }
      // Child odd nodes(status = state + 1) can be ignored
    }
  }
  return false;
}

int solve(vector<int> nodes, unordered_set<int> nums) {
  vector<vector<int>> graph(nodes.size() + 1);  // 1-based
  for (int i = 0; i < nodes.size(); ++i) {
    for (int j = i + 1; j < nodes.size(); ++j) {
      if (nums.find(nodes[i] + nodes[j]) != nums.end()) {
        graph[i + 1].push_back(j + 1);
        graph[j + 1].push_back(i + 1);
      }
    }
  }

  // blossom
  // match: index of matching node
  // status: even = state, odd = state + 1, previous: status[node] < state
  // parent: parent node during this iteration
  vector<int> match(graph.size()), status(graph.size(), -1),
      parent(graph.size());
  int ans = 0;
  for (int i = 1, state = 0; i < match.size(); ++i, state += 2) {
    if (!match[i])
      if (augment(graph, match, status, parent, state, i)) ++ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases;
  while (cases--) {
    int node_cnt, set_cnt;
    cin >> node_cnt >> set_cnt;
    vector<int> nodes(node_cnt);
    unordered_set<int> nums(set_cnt);
    for (auto &x : nodes) cin >> x;
    for (int i = 0, inp; i < set_cnt; ++i) {
      cin >> inp;
      nums.insert(inp);
    }
    cout << solve(nodes, nums) << "\n";
  }
}