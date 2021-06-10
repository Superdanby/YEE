#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<ll> &nums) {
  for (int i = 2; i < nums.size(); ++i)
    nums[i] += nums[i - 1] < nums[i - 2] ? nums[i - 1] : nums[i - 2];
  return nums.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt;
  cin >> num_cnt;
  vector<ll> nums(num_cnt);
  for (auto &x : nums) cin >> x;
  cout << solve(nums) << "\n";

  return 0;
}
