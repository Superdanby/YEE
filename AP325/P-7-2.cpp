#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<vector<int>> &graph, const vector<int> &values) {
  vector<bool> visited(values.size());
  int ans = 0;
  for (int i = 0; i < values.size(); ++i) {
    queue<int> que;
    que.push(i);
    int local = 0;
    while (!que.empty()) {
      if (!visited[que.front()]) {
        visited[que.front()] = true;
        local += values[que.front()];
        for (const auto &x : graph[que.front()])
          if (!visited[x]) que.push(x);
      }
      que.pop();
    }
    ans = local > ans ? local : ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertices, edges;
  cin >> vertices >> edges;
  vector<int> values(vertices);
  for (auto &x : values) cin >> x;
  vector<vector<int>> graph(vertices);
  int from, to;
  while (edges--) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  cout << solve(graph, values) << "\n";

  return 0;
}
