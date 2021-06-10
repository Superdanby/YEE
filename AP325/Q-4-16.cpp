#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 62;

ll solve(vector<pair<ll, ll>> &num) {
  sort(num.begin(), num.end());

  ll ans = 0, time = 0;
  for (const auto &x : num) {
    time += x.first;
    ans += x.second - time;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<pair<ll, ll>> num(nums);
  for (auto &x : num) cin >> x.first;
  for (auto &x : num) cin >> x.second;

  cout << solve(num) << "\n";

  return 0;
}