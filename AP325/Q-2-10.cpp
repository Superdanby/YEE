#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
    x = 1, y = 0;
    return a;
  }
  ll ret = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
}

void brute_force(vector<ll> &nums, size_t begin, size_t end, set<ll> &values) {
  set<ll> origin;
  for (auto i = begin; i < end; ++i) {
    // combination only containing nums[i]
    values.insert(nums[i]);
    for (const auto &x : origin) {
      // combinations not choosing nums[i]
      values.insert(x);
      // combinations containing nums[i] and others
      values.insert(nums[i] + x);
    }
    origin.swap(values);
    values.clear();
  }
  values.swap(origin);
  // for (auto it = values.begin(); it != values.end(); ++it) cout << *it << "
  // "; cout << "\n";
}
// a % b = 1 a = qb + 1 ax - yMOD = 1
ll solve(vector<ll> &nums, ll &target) {
  set<ll> left, right;
  brute_force(nums, 0, nums.size() / 2, left);
  brute_force(nums, nums.size() / 2, nums.size(), right);
  ll ans = -1;
  if (left.size() > 0) {
    auto it = left.upper_bound(target);
    if (it != left.begin()) --it;
    ans = *it <= target ? *it : ans;
    // cout << *it << " " << ans << "\n";
  }
  if (right.size() > 0) {
    auto it = right.upper_bound(target);
    // cout << *it << "\n";
    if (it != right.begin()) --it;
    ans = *it <= target && ans < *it ? *it : ans;
    // cout << *it << " " << ans << "\n";
  }
  for (auto it = left.begin(); right.size() > 0 && it != left.end(); ++it) {
    auto rit = right.upper_bound(target - *it);
    if (rit != right.begin()) --rit;
    ans = *it + *rit <= target && ans < *it + *rit ? *it + *rit : ans;
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
