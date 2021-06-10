#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<ll> &nums) {
  vector<ll> seq;
  for (const auto &x : nums) {
    auto it = lower_bound(seq.begin(), seq.end(), x);
    if (it == seq.end())
      seq.push_back(x);
    else
      *it = x;
  }
  return seq.size();
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
