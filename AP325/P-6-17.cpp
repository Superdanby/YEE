#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<ll> &nums) {
  vector<vector<ll>> dp(nums.size(), vector<ll>(nums.size(), INF));
  for (int i = 0; i < nums.size() - 1; ++i) dp[i][i + 1] = 0;
  for (int seqs = 1; seqs < nums.size(); ++seqs) {
    for (int i = seqs; i < nums.size(); ++i) {
      for (int j = i - seqs + 1; j < i; ++j)
        dp[i - seqs][i] =
            dp[i - seqs][j] + dp[j][i] + nums[i] - nums[i - seqs] <
                    dp[i - seqs][i]
                ? dp[i - seqs][j] + dp[j][i] + nums[i] - nums[i - seqs]
                : dp[i - seqs][i];
    }
  }
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << " ";
  //   cerr << "\n";
  // }
  return dp.front().back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt, back;
  cin >> num_cnt >> back;

  vector<ll> nums(num_cnt + 1);
  for (int i = 1; i < nums.size(); ++i) cin >> nums[i];
  nums.push_back(back);

  cout << solve(nums) << "\n";

  return 0;
}
