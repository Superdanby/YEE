#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<ll> &nums, ll &target) {
  set<ll> prefixes;
  ll prefix = 0, ans = nums.front();

  for (auto &x : nums) {
    prefix += x;
    ans = prefix > ans && prefix <= target ? prefix : ans;
    auto it = prefixes.lower_bound(prefix - target);
    if (it != prefixes.end()) ans = prefix - *it > ans ? prefix - *it : ans;
    prefixes.insert(prefix);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  ll target;
  cin >> nums >> target;
  vector<ll> inp(nums);
  for (auto &x : inp) {
    cin >> x;
  }
  cout << solve(inp, target) << "\n";

  return 0;
}
