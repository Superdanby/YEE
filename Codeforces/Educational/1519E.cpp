// TLE
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

constexpr const ld err = 1e-9;

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
  vector<vector<int>> graph(nodes.size() + 1);  // 1-base
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

inline bool pairable(pair<ld, ld> &a, pair<ld, ld> &b) {
  auto temp = (a.first + 1) * b.second - a.second * (b.first + 1);
  if (temp > 0 ? temp < err : (-temp) < err) return true;
  temp = (a.first + 1) * (b.second + 1) - a.second * b.first;
  if (temp > 0 ? temp < err : (-temp) < err) return true;
  temp = a.first * (b.second + 1) - (a.second + 1) * b.first;
  if (temp > 0 ? temp < err : (-temp) < err) return true;
  temp = a.first * b.second - (a.second + 1) * (b.first + 1);
  if (temp > 0 ? temp < err : (-temp) < err) return true;
  return false;
}

void solve(vector<pair<ld, ld>> &nodes) {
  vector<vector<int>> graph(nodes.size() + 1);  // 1-based
  for (int i = 0; i < nodes.size(); ++i) {
    for (int j = i + 1; j < nodes.size(); ++j) {
      if (pairable(nodes[i], nodes[j])) {
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
  cout << ans << "\n";
  for (int i = 1; i < match.size(); ++i) {
    if (match[i]) {
      cout << i << " " << match[i] << "\n";
      match[match[i]] = 0;
    }
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  ld a, b, c, d;
  vector<pair<ld, ld>> nodes(node_cnt);
  for (auto &x : nodes) {
    cin >> a >> b >> c >> d;
    x.first = a / b;
    x.second = c / d;
  }

  solve(nodes);
}