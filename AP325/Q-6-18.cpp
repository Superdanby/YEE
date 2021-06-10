#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<int> &nums) {
  vector<vector<ll>> dp(
      nums.size(), vector<ll>(nums.size(), INF));  // best value of nums[i: j]
  for (int i = 0; i + 1 < nums.size(); ++i) dp[i][i + 1] = 0;
  for (int i = 2; i < nums.size(); ++i) {
    for (int j = 0; j + i < nums.size(); ++j) {
      for (int k = j + 1; k < j + i; ++k) {
        // cerr << j << " " << k << " " << j + i << "\n";
        dp[j][j + i] =
            dp[j][k] + dp[k][j + i] + nums[j] * nums[k] * nums[j + i] <
                    dp[j][j + i]
                ? dp[j][k] + dp[k][j + i] + nums[j] * nums[k] * nums[j + i]
                : dp[j][j + i];
      }
    }
  }
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << setw(20) << y << " ";
  //   cerr << "\n";
  // }
  return dp.front().back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num_cnt;
  cin >> num_cnt;
  vector<int> nums(num_cnt + 1);
  for (auto &x : nums) cin >> x;
  cout << solve(nums) << "\n";

  return 0;
}
