#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

void solve(const vector<int> &nums) {
  map<int, int> progress;  // end, start
  vector<int> ans(nums.size());
  for (int i = 0; i < nums.size(); ++i) {
    if (progress.empty() || i + nums[i] > (progress.rbegin()->first))
      progress.insert({i + nums[i], i});
    while (!progress.empty() && (progress.begin()->first) <= i)
      progress.erase(progress.begin());
    if (!progress.empty() && i >= (progress.begin()->second))
      ans[i] = i - (progress.begin()->second) + 1;
  }
  auto it = ans.begin();
  cout << *it;
  for (++it; it != ans.end(); ++it) cout << " " << *it;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt;
  cin >> num_cnt;
  vector<int> nums(--num_cnt);
  for (auto &x : nums) cin >> x;
  solve(nums);

  return 0;
}