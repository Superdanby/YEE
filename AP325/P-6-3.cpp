#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(vector<ll> &nums) {
  for (int i = 3; i < nums.size(); ++i) {
    ll accum = nums[i - 2] < nums[i - 3] ? nums[i - 2] : nums[i - 3];
    nums[i] += accum < nums[i - 1] ? accum : nums[i - 1];
  }
  return nums[nums.size() - 2] < nums.back() ? nums[nums.size() - 2]
                                             : nums.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt;
  cin >> num_cnt;
  vector<ll> nums(num_cnt + 1);
  fill(nums.begin(), nums.begin() + 1, INF);
  for (int i = 1; i < nums.size(); ++i) cin >> nums[i];
  cout << solve(nums) << "\n";

  return 0;
}