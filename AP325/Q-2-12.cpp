#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll solve(vector<vector<ll>> &nums, const ll target) {
  for (int i = 1; i < nums.size(); ++i) {
    for (int j = 0; j < nums[i].size(); ++j) nums[i][j] += nums[i - 1][j];
  }

  ll ans = nums.front().front();

  // M: 0 ~ i
  for (int i = 0; i < nums.size(); ++i) {
    set<ll> prefixes;
    ll prefix = 0;
    for (auto &x : nums[i]) {
      prefix += x;
      ans = prefix > ans && prefix <= target ? prefix : ans;
      auto it = prefixes.lower_bound(prefix - target);
      if (it != prefixes.end()) ans = prefix - *it > ans ? prefix - *it : ans;
      prefixes.insert(prefix);
    }
  }

  // M: i ~ j
  for (int i = 0; i < nums.size(); ++i) {
    for (int j = i + 1; j < nums.size(); ++j) {
      set<ll> prefixes;
      ll prefix = 0;
      for (int k = 0; k < nums[i].size(); ++k) {
        prefix += nums[j][k] - nums[i][k];
        ans = prefix > ans && prefix <= target ? prefix : ans;
        auto it = prefixes.lower_bound(prefix - target);
        if (it != prefixes.end()) ans = prefix - *it > ans ? prefix - *it : ans;
        prefixes.insert(prefix);
      }
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  ll target, M, N;
  cin >> target >> M >> N;  // M <= 50
  vector<vector<ll>> inp(M, vector<ll>(N));
  for (auto &x : inp) {
    for (auto &y : x) cin >> y;
  }
  cout << solve(inp, target) << "\n";

  return 0;
}
