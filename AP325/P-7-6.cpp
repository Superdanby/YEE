#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

// constexpr vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(const vector<vector<pair<int, int>>> &edges, const int start,
           const int stop) {
  vector<pair<int, int>> costs(edges.size(), {INF, -INF});
  costs[start] = {0, 0};
  queue<int> low_que, high_que;
  low_que.push(start);
  high_que.push(start);
  while (!low_que.empty()) {
    auto x = low_que.front();
    low_que.pop();
    if (x == stop) continue;
    for (const auto &y : edges[x]) {
      if (costs[x].first + y.second < costs[y.first].first) {
        costs[y.first].first = costs[x].first + y.second;
        low_que.push(y.first);
      }
    }
  }
  while (!high_que.empty()) {
    auto x = high_que.front();
    high_que.pop();
    if (x == stop) continue;
    for (const auto &y : edges[x]) {
      if (costs[x].second + y.second > costs[y.first].second) {
        costs[y.first].second = costs[x].second + y.second;
        high_que.push(y.first);
      }
    }
  }
  if (costs[stop].first == INF)
    cout << "No path\n"
         << "No path\n";
  else
    cout << costs[stop].first << "\n" << costs[stop].second << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt, edge_cnt;
  cin >> vertex_cnt >> edge_cnt;
  int start, stop;
  cin >> start >> stop;
  vector<vector<pair<int, int>>> edges(edge_cnt);
  int from, to, cost;
  for (auto &x : edges) {
    cin >> from >> to >> cost;
    edges[from].push_back({to, cost});
  }
  solve(edges, start, stop);

  return 0;
}