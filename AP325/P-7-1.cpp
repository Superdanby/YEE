#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<vector<int>> &graph, const int start) {
  vector<int> dist(graph.size(), -1);
  queue<int> que;
  dist[start] = 0;
  que.push(start);
  ll ans = 0, cnt = 0;
  while (!que.empty()) {
    for (const auto &x : graph[que.front()]) {
      if (dist[x] == -1) {
        dist[x] = dist[que.front()] + 1;
        ans += dist[x];
        ++cnt;
        que.push(x);
      }
    }
    que.pop();
  }
  cout << cnt << "\n";
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertices, edges, start;
  cin >> vertices >> edges >> start;
  vector<vector<int>> graph(vertices);
  int from, to;
  while (edges--) {
    cin >> from >> to;
    graph[from].push_back(to);
  }
  cout << solve(graph, start) << "\n";

  return 0;
}
