#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<int>> &graph, const vector<ll> &costs,
              vector<ll> &best, const int node) {
  for (const auto &x : graph[node]) {
    if (best[x] == -1) {
      best[x] = 0;
      traverse(graph, costs, best, x);
      best[node] += best[x] > 0 ? best[x] : 0;
    }
  }
  best[node] += costs[node];
}

ll solve(vector<vector<int>> &graph, vector<ll> &costs) {
  vector<ll> best(costs.size(), -1);
  best[1] = 0;
  traverse(graph, costs, best, 1);
  ll ans = 0;
  for (const auto &x : best) ans = x > ans ? x : ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<int>> graph(node_cnt + 1);  // node, value
  vector<ll> costs(graph.size());
  for (int i = 1; i < costs.size(); ++i) cin >> costs[i];
  int from, to;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  cout << solve(graph, costs) << "\n";

  return 0;
}
