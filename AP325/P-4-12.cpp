#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num) {
  ll low = num.front(), high = num.front(), ans = 0;
  for (const auto &x : num) {
    if (x < low) {
      high = low = x;
    } else {
      high = x > high ? x : high;
    }
    ans = high - low > ans ? high - low : ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<ll> num(nums);
  for (auto &x : num) cin >> x;

  cout << solve(num) << "\n";

  return 0;
}