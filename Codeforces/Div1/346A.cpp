#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

inline int gcd(int a, int b) {
  if (!b) return a;
  return gcd(b, a % b);
}

string solve(const vector<int> &nums) {
  int val = nums.front();
  int MAX = 0;
  for (const auto &x : nums) {
    val = gcd(val, x);
    MAX = x > MAX ? x : MAX;
  }
  MAX /= val;
  if ((MAX - nums.size()) & 1) return "Alice";
  return "Bob";
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