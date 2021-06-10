#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<int> &prices, const int times) {
  vector<vector<int>> dp(
      times + 1,
      vector<int>(prices.size()));  // dp[i][j]: best value of [0,j] when buying
                                    // ans selling is limited to j times

  for (int i = 1; i <= times; ++i) {
    int prefix = 0;
    for (int j = 1; j < dp[i].size(); ++j) {
      // // select prices[i]
      prefix = (dp[i - 1][j - 1] > prefix ? dp[i - 1][j - 1] : prefix) +
               prices[j] - prices[j - 1];
      dp[i][j] = prefix;
      // for (int k = 0; k < j; ++k) {
      //   dp[i][j] = dp[i - 1][k] + prices[j] - prices[k] > dp[i][j]
      //                  ? dp[i - 1][k] + prices[j] - prices[k]
      //                  : dp[i][j];
      // }
      // don't select prices[i]
      dp[i][j] = dp[i][j - 1] > dp[i][j] ? dp[i][j - 1] : dp[i][j];
      // dp[i][j] = dp[i - 1][j - 1] + prices[j] - prices[j - 1] >
      //                    dp[i][j - 1] + prices[j] - prices[j - 1]
      //                ? dp[i - 1][j - 1] + prices[j] - prices[j - 1]
      //                : dp[i][j - 1] + prices[j] - prices[j - 1];
    }
  }

  // ll ans = 0;
  // for (const auto &x : dp.back()) ans = x > ans ? x : ans;
  // for (const auto &x : prices) cerr << x << " ";
  // cerr << "\n";
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << " ";
  //   cerr << "\n";
  // }

  return dp.back().back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num_cnt, times;
  cin >> num_cnt >> times;
  vector<int> prices(num_cnt);
  for (auto &x : prices) cin >> x;
  cout << solve(prices, times) << "\n";

  return 0;
}