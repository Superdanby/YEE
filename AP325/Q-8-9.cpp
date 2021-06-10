#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<int>> &graph, vector<vector<ll>> &dp,
              const int node) {
  bool leaf = true;
  ll amend = INF;
  for (const auto &x : graph[node]) {
    if (dp[0][x] == INF) {
      dp[0][x] = 0;
      dp[2][x] = 0;
      leaf = false;
      traverse(graph, dp, x);
      ll select = dp[0][x] < dp[1][x] ? dp[0][x] : dp[1][x];
      dp[0][node] += select < dp[2][x] ? select : dp[2][x];
      amend = dp[0][x] - dp[1][x] < amend ? dp[0][x] - dp[1][x] : amend;
      dp[1][node] += dp[0][x] < dp[1][x] ? dp[0][x] : dp[1][x];
      dp[2][node] += dp[1][x];
    }
  }
  ++dp[0][node];
  if (!leaf) {
    dp[1][node] -= INF;
    if (amend > 0) dp[1][node] += amend;
  }
  // cerr << "node: " << node << "\n";
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << ' ';
  //   cerr << "\n";
  // }
  // cerr << "\n";
}

ll solve(vector<vector<int>> &graph) {
  vector<vector<ll>> dp(
      3, vector<ll>(graph.size(), INF));  // select,  beside, not beside
  dp[0][1] = dp[2][1] = 0;
  traverse(graph, dp, 1);
  ll ans = dp[0][1] < dp[2][1] + 1 ? dp[0][1] : dp[2][1] + 1;
  return ans < dp[1][1] ? ans : dp[1][1];
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<int>> graph(node_cnt + 1);  // node, value
  int from, to;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from >> to;
    graph[from].push_back(to);
    graph[to].push_back(from);
  }
  cout << solve(graph) << "\n";

  return 0;
}
