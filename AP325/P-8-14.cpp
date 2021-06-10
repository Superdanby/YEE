#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<int>> &graph, const int node,
              vector<int> &level) {
  for (const auto &x : graph[node]) {
    if (level[x] == -1) {
      level[x] = level[node] + 1;
      traverse(graph, x, level);
    }
  }
}

ll solve(vector<vector<int>> &graph) {
  int start = 0;
  vector<int> level(graph.size(), -1);
  level[start] = 0;
  traverse(graph, start, level);
  int max_level = 0;
  start = 0;
  for (int i = 0; i < level.size(); ++i) {
    if (level[i] > max_level) {
      max_level = level[i];
      start = i;
    }
  }
  fill(level.begin(), level.end(), -1);
  level[start] = 0;
  traverse(graph, start, level);
  max_level = 0;
  start = 0;
  for (const auto &x : level) {
    if (x > max_level) {
      max_level = x;
    }
  }
  return max_level;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<int>> graph(node_cnt);  // node, value
  int from, to;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  cout << solve(graph) << "\n";

  return 0;
}
