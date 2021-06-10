#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num) {
  ll ans = 0, acc = 0;
  for (auto &x : num) {
    acc = acc + x > 0 ? acc + x : 0;
    ans = acc > ans ? acc : ans;
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
