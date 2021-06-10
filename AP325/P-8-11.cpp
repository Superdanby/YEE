#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<pair<int, int>>> &graph,
              vector<vector<ll>> &dp, const int node) {
  for (const auto &x : graph[node]) {
    if (!dp[0][x.first]) {
      dp[0][x.first] += x.second;
      traverse(graph, dp, x.first);
      dp[1][node] +=
          dp[0][x.first] > dp[1][x.first] ? dp[0][x.first] : dp[1][x.first];
      dp[0][node] += dp[1][x.first];
    }
  }
}

ll solve(vector<vector<pair<int, int>>> &graph) {
  vector<vector<ll>> dp(2, vector<ll>(graph.size()));  // select, give up
  dp[0][1] = graph[0][0].second;
  traverse(graph, dp, 1);

  return dp[0][1] > dp[1][1] ? dp[0][1] : dp[1][1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;

  vector<vector<pair<int, int>>> graph(node_cnt + 1);  // node, value
  int from, value;
  cin >> value;
  graph[0].push_back({1, value});
  for (int i = 2; i <= node_cnt; ++i) {
    cin >> from >> value;
    graph[from].push_back({i, value});
  }
  cout << solve(graph) << "\n";

  return 0;
}
