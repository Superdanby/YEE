#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<int>> &graph, vector<vector<ll>> &dp,
              const int node) {
  for (const auto &x : graph[node]) {
    traverse(graph, dp, x);
    dp[0][node] += dp[0][x] < dp[1][x] ? dp[0][x] : dp[1][x];
    dp[1][node] += dp[0][x];
  }
  ++dp[0][node];
  // cerr << "node: " << node << "\n";
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << ' ';
  //   cerr << "\n";
  // }
  // cerr << "\n";
}

ll solve(vector<vector<int>> &graph) {
  vector<vector<ll>> dp(2, vector<ll>(graph.size()));  // select,  beside
  traverse(graph, dp, 0);
  return dp[0][0] < dp[1][0] ? dp[0][0] : dp[1][0];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<int>> graph(node_cnt);  // node, value
  int from, to;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from;
    graph[from].push_back(i);
  }
  cout << solve(graph) << "\n";

  return 0;
}
