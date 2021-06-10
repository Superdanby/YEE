#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

ll solve(vector<ll> &num, ll &ubound, size_t index, ll ans) {
  if (ans > ubound) return -1;
  if (index == num.size()) return ans;
  ll x = solve(num, ubound, index + 1, ans);
  ll y = solve(num, ubound, index + 1, ans + num[index]);
  return x > y ? x : y;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  ll nums, ubound;
  cin >> nums >> ubound;
  vector<ll> num(nums);
  for (auto &x : num) cin >> x;

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(num, ubound, 0, 0) << "\n";

  return 0;
}
