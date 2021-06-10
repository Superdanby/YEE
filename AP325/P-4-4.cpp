#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<ll, ll>> &num) {
  sort(num.begin(), num.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
  });
  ll end = -1, ans = 0;
  for (const auto &x : num) {
    if (x.first > end) {
      ++ans;
      end = x.second;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<pair<ll, ll>> num(nums);
  for (auto &x : num) cin >> x.first >> x.second;

  cout << solve(num) << "\n";

  return 0;
}
