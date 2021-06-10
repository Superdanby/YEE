#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<int> &nums) {
  if (nums.size() < 2) return 0;
  vector<int> fir(nums.begin(), nums.begin() + nums.size() / 2);
  vector<int> sec(nums.begin() + nums.size() / 2, nums.end());
  ll ans = solve(fir);
  ans += solve(sec);
  for (int i = 0, j = 0, k = 0; i < nums.size(); ++i) {
    if (j < fir.size() && k < sec.size()) {
      if (fir[j] <= sec[k])
        nums[i] = fir[j++];
      else {
        nums[i] = sec[k++];
        ans += fir.size() - j;
      }
    } else if (j < fir.size()) {
      nums[i] = fir[j++];
    } else {
      nums[i] = sec[k++];
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt;
  cin >> num_cnt;
  vector<int> nums(num_cnt);
  for (auto &x : nums) cin >> x;

  cout << solve(nums) << "\n";

  return 0;
}
