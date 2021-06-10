#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num) {
  sort(num.begin(), num.end());
  ll ans = num[0];
  for (int i = 1; i < num.size(); ++i) {
    num[i] += num[i - 1];
    ans += num[i];
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
