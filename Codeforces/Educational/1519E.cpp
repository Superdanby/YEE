// TLE, algorithm not verified
#include <bits/stdc++.h>

using namespace std;

typedef long double ld;

constexpr const ld err = 1e-9;

inline int lca(vector<vector<int>> &graph, vector<int> &parent, int a,
               int b) {
  static vector<int> visited(graph.size());
  static int visit = 0;
  ++visit;
  // visit = 2
  // 0 - 1 - 1    0 - 1 - 2    0 - 1 - 2    0 - 2 - 2
  //     | /   ->     |     ->     |     ->     |
  //     0            0            2            2
  while (visited[a] != visit) {
    visited[a] = visit;
    a = parent[a];
    if (b != -1) swap(a, b);
  }
  return a;
}

bool augment(vector<vector<int>> &graph, vector<int> &match,
             vector<int> &status, vector<int> &parent, vector<int> &flower,
             const int state, const int root) {
  queue<int> que;
  que.push(root);
  status[root] = state;
  while (que.size()) {
    const auto node = que.front();
    que.pop();
    for (const auto &x : graph[node]) {
      if (x == root) continue;
      if (match[x] == -1) {
        // Before: 0, 1 <-> 2, 3 <-> 4, 5
        // After: 0 <-> 1, 2 <-> 3, 4 <-> 5
        auto cnt = 0;
        for (auto _node = node, new_match = x, old_match = -2;;
             _node = parent[old_match], new_match = old_match) {
          ++cnt;
          if (cnt > 100) exit(1);
          old_match = match[_node];
          match[_node] = new_match;
          match[new_match] = _node;
          if (old_match == -1) break;
        }
        return true;
      } else if (status[x] < state) {  // node not visited with current root
        parent[x] = node;
        status[x] = state + 1;
        if (status[match[x]] < state) {
          parent[match[x]] = x;
          status[match[x]] = state;
          que.push(match[x]);
        }
      } else if (status[x] == state &&
                 flower[node] !=
                     flower[x]) {  // flower, node and child are both even nodes
        const auto flower_root = lca(graph, parent, node, x);
        // https://jacky860226.github.io/general-graph-weighted-match-slides/img/pa_set.png
        for (int i = 0, even_node = x, new_parent = node; i < 2;
             ++i, swap(even_node, new_parent)) {
          while (even_node != flower_root) {
            parent[even_node] = new_parent;
            // All nodes in a flower are even
            status[new_parent = match[even_node]] = state;
            flower[even_node] = flower[new_parent] = flower_root;
            que.push(new_parent);
            even_node = parent[new_parent];
          }
        }
      }
      // Child odd nodes(status = state + 1) can be ignored
    }
  }
  return false;
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
  vector<vector<int>> graph(nodes.size());
  for (int i = 0; i < nodes.size(); ++i) {
    for (int j = i + 1; j < nodes.size(); ++j) {
      if (pairable(nodes[i], nodes[j])) {
        graph[i].push_back(j);
        graph[j].push_back(i);
      }
    }
  }
  nodes.clear();

  // blossom
  // match: index of matching node
  // status: even = state, odd = state + 1, previous visted < state
  // parent: parent node during this iteration
  vector<int> match(graph.size(), -1), status(graph.size(), -1),
      parent(graph.size(), -1), flower(graph.size());
  for (int i = 0; i < flower.size(); ++i) flower[i] = i;
  int ans = 0;
  for (int i = 0, state = 0; i < match.size(); ++i, state += 2) {
    if (match[i] == -1) {
      status[i] = state;
      parent[i] = -1;
      if (augment(graph, match, status, parent, flower, state, i)) ++ans;
    }
  }
  cout << ans << "\n";
  for (int i = 0; i < match.size(); ++i) {
    if (match[i] != -1) {
      cout << i + 1 << " " << match[i] + 1 << "\n";
      match[match[i]] = -1;
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