#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(const vector<ll> &nums) {
  vector<ll> l_small(nums.size()), r_small(nums.size());
  l_small.front() = -1;
  r_small.back() = nums.size();
  for (int i = 1; i < nums.size(); ++i) {
    int j = i - 1;
    while (j >= 0 && nums[j] >= nums[i]) j = l_small[j];
    l_small[i] = j;
    j = nums.size() - i;
    while (j < nums.size() && nums[j] >= nums[nums.size() - i - 1])
      j = r_small[j];
    r_small[nums.size() - i - 1] = j;
  }
  // for (const auto &x : l_small) cerr << x << " ";
  // cerr << "\n";
  // for (const auto &x : r_small) cerr << x << " ";
  // cerr << "\n";
  ll ans = 0;
  for (int i = 0; i < nums.size(); ++i) {
    ll product = nums[i] * (r_small[i] - l_small[i] - 1);
    ans = product > ans ? product : ans;
  }
  return ans;
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
