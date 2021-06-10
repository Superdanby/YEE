#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
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

void brute_force(vector<ll> &nums, size_t begin, size_t end,
                 unordered_map<ll, ll> &values) {
  unordered_map<ll, ll> origin;
  for (auto i = begin; i < end; ++i) {
    // combination only containing nums[i]
    if (values.find(nums[i]) == values.end()) {
      values[nums[i]] = 1;
    } else {
      values[nums[i]] = (values[nums[i]] + 1) % MOD;
    }
    for (const auto &x : origin) {
      ll new_num = x.first * nums[i] % MOD;
      // combinations not choosing nums[i]
      if (values.find(x.first) == values.end()) {
        values[x.first] = x.second;
      } else {
        values[x.first] = (values[x.first] + x.second) % MOD;
      }
      // combinations containing nums[i] and others
      if (values.find(new_num) == values.end()) {
        values[new_num] = x.second;
      } else {
        values[new_num] = (values[new_num] + x.second) % MOD;
      }
    }
    origin.swap(values);
    values.clear();
  }
  values.swap(origin);
  for (auto &x : values) {
    x.second %= MOD;
  }
}
// a % b = 1 a = qb + 1 ax - yMOD = 1
ll solve(vector<ll> &nums) {
  unordered_map<ll, ll> left, right;
  brute_force(nums, 0, nums.size() / 2, left);
  brute_force(nums, nums.size() / 2, nums.size(), right);
  ll ans = 0;
  if (left.find(1) != left.end()) ans = (left[1]) % MOD;
  if (right.find(1) != right.end()) ans = (ans + right[1]) % MOD;
  ll x, y;
  for (const auto &a : left) {
    extgcd(a.first, MOD, x, y);
    x = x < 0 ? x + MOD : x;
    // if (a.first * x % MOD != 1) exit(1);
    if (right.find(x) != right.end())
      ans = (ans + a.second * right[x] % MOD) % MOD;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums >> MOD;
  if (MOD == 1) {
    cout << "0\n";
    return 0;
  }
  vector<ll> inp(nums);
  for (auto &x : inp) {
    cin >> x;
    x %= MOD;
  }
  cout << solve(inp) << "\n";

  return 0;
}
