#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

// constexpr vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

void solve(const vector<vector<pair<int, int>>> &edges) {
  vector<ll> costs(edges.size(), INF);
  costs[0] = 0;
  queue<int> que;
  que.push(0);
  unordered_set<int> us;
  while (!que.empty()) {
    auto x = que.front();
    que.pop();
    for (const auto &y : edges[x]) {
      if (costs[x] + y.second < costs[y.first]) {
        costs[y.first] = costs[x] + y.second;
        us.insert(y.first);
      }
    }
    if (que.empty()) {
      for (const auto y : us) que.push(y);
      us.clear();
    }
  }
  // for (const auto &z : costs) cout << z << " ";
  // cout << " ";
  ll cnt = 0, MAX = 0;
  for (const auto &x : costs)
    if (x == INF)
      ++cnt;
    else
      MAX = x > MAX ? x : MAX;
  cout << MAX << "\n" << cnt << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt, edge_cnt;
  cin >> vertex_cnt >> edge_cnt;
  vector<vector<pair<int, int>>> edges(vertex_cnt);
  int from, to, cost;
  while (edge_cnt--) {
    cin >> from >> to >> cost;
    edges[from].push_back({to, cost});
    edges[to].push_back({from, cost});
  }
  solve(edges);

  return 0;
}
