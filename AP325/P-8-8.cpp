#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void traverse(vector<vector<int>> &tree, vector<vector<int>> &dp,
              const int node) {
  ++dp[0][node];
  if (tree[node].empty()) return;
  for (const auto &x : tree[node]) {
    traverse(tree, dp, x);
    dp[0][node] += dp[1][x];
    dp[1][node] += dp[0][x] > dp[1][x] ? dp[0][x] : dp[1][x];
  }
  // cerr << "Node: " << node << "\n";
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << " ";
  //   cerr << "\n";
  // }
  // cerr << "\n";
}

int solve(vector<int> &tree) {
  vector<vector<int>> dp(2,
                         vector<int>(tree.size() + 1));  // choose, give up
  vector<vector<int>> child_orientation(tree.size() + 1);
  for (int i = 1; i <= tree.size(); ++i)
    child_orientation[tree[i - 1]].push_back(i);
  // for (int i = 0; i < child_orientation.size(); ++i) {
  //   cerr << i << ": ";
  //   for (const auto &y : child_orientation[i]) cerr << y << " ";
  //   cerr << "\n";
  // }
  traverse(child_orientation, dp, 0);

  return dp.front().front() > dp.back().front() ? dp.front().front()
                                                : dp.back().front();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<int> nodes(node_cnt - 1);
  for (auto &x : nodes) cin >> x;
  cout << solve(nodes) << "\n";

  return 0;
}
