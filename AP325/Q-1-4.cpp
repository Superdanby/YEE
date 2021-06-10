#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
constexpr const ll MAX = 1e18;

ll solve(vector<ll>& num, int left, int right, int depth) {
  if (!depth || right - left < 2) return 0;
  vector<ll> prefix(right - left + 1), suffix(right - left + 1);
  for (size_t i = 1, j = suffix.size() - 2, pre = 0, suf = 0; i < prefix.size();
       ++i, --j) {
    pre += num[i + left - 1];
    suf += num[j + left + 1];
    prefix[i] = prefix[i - 1] + pre;
    suffix[j] = suffix[j + 1] + suf;
  }
  // for (const auto& x : prefix) cout << x << " ";
  // cout << "\n";
  // for (const auto& x : suffix) cout << x << " ";
  // cout << "\n\n";
  int idx = -1;
  ll val = MAX;
  for (size_t i = 1; i < prefix.size() - 1; ++i) {
    if (abs(prefix[i] - suffix[i]) < val) {
      idx = i + left;
      val = abs(prefix[i] - suffix[i]);
    }
  }
  return num[idx] + solve(num, left, idx - 1, depth - 1) +
         solve(num, idx + 1, right, depth - 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int nums, depth;
  cin >> nums >> depth;
  vector<ll> num(nums);
  for (auto& x : num) cin >> x;
  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(num, 0, num.size() - 1, depth) << "\n";

  return 0;
}
