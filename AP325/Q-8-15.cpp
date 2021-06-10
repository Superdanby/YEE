#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<pair<int, ll>>> &graph, vector<ll> &costs,
              const int node) {
  for (const auto &x : graph[node]) {
    if (costs[x.first] == -1) {
      costs[x.first] = costs[node] + x.second;
      traverse(graph, costs, x.first);
    }
  }
}

ll solve(vector<vector<pair<int, ll>>> &graph) {
  vector<ll> costs(graph.size(), -1);
  int start = 0;
  costs[start] = 0;
  traverse(graph, costs, start);
  ll cost = 0;
  for (int i = 0; i < costs.size(); ++i) {
    if (costs[i] > cost) {
      cost = costs[i];
      start = i;
    }
  }
  fill(costs.begin(), costs.end(), -1);
  costs[start] = 0;
  traverse(graph, costs, start);
  for (const auto &x : costs) cost = x > cost ? x : cost;
  ll ans = 0;
  for (const auto &x : graph)
    for (const auto &y : x) ans += y.second;
  return ans - cost;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<pair<int, ll>>> graph(node_cnt);  // node, value
  int from, to, cost;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from >> to >> cost;
    graph[from].push_back({to, cost});
    graph[to].push_back({from, cost});
  }
  cout << solve(graph) << "\n";

  return 0;
}
