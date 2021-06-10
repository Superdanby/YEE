#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

// constexpr vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ll solve(const vector<vector<int>> &graph) {
  int start_i = 0, start_j = 0, MIN = graph.front().front();
  for (int i = 0; i < graph.size(); ++i)
    for (int j = 0; j < graph[i].size(); ++j)
      if (graph[i][j] < MIN) {
        MIN = graph[i][j];
        start_i = i, start_j = j;
      }
  vector<vector<bool>> visited(
      graph.size() + 2, vector<bool>(graph.front().size() + 2));  // padded 0
  for (int i = 0; i < visited.front().size(); ++i) {
    visited.front()[i] = true;
    visited.back()[i] = true;
  }
  for (int i = 0; i < visited.size(); ++i) {
    visited[i].front() = true;
    visited[i].back() = true;
  }

  queue<pair<int, int>> que;
  que.push({start_i, start_j});
  int ans = 0;
  while (!que.empty()) {
    auto x = que.front();
    que.pop();
    visited[x.first + 1][x.second + 1] = true;
    ans += graph[x.first][x.second];
    MIN = 0x3f3f3f3f;
    int next_i = -1, next_j = -1;
    for (const auto &y : direction)
      if (!visited[x.first + y.first + 1][x.second + y.second + 1] &&
          graph[x.first + y.first][x.second + y.second] < MIN) {
        next_i = x.first + y.first, next_j = x.second + y.second;
        MIN = graph[x.first + y.first][x.second + y.second];
      }
    if (next_i != -1) que.push({next_i, next_j});
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int rows, cols;
  cin >> rows >> cols;
  vector<vector<int>> graph(rows, vector<int>(cols));
  for (auto &x : graph)
    for (auto &y : x) cin >> y;
  cout << solve(graph) << "\n";

  return 0;
}
