#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(vector<ll> &nums, const int all, const int need) {
  ll target = need;
  for (const auto &x : nums) target += x;
  target -= all;
  if (target <= 0) return 0;
  ll ans = INF;
  vector<bool> dp(target + 1);
  dp.front() = true;
  for (const auto &x : nums) {
    for (int i = target; i >= x; --i) {
      if (dp[i] && i + x >= target) ans = i + x < ans ? i + x : ans;
      dp[i] = dp[i] | dp[i - x];
    }
    if (x >= target) ans = x < ans ? x : ans;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt, all, need;
  cin >> num_cnt >> all >> need;
  vector<ll> nums(num_cnt);
  for (auto &x : nums) cin >> x;

  cout << solve(nums, all, need) << "\n";

  return 0;
}
