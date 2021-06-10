#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<ll, ll>> &num) {
  sort(num.begin(), num.end(), [](pair<ll, ll> &a, pair<ll, ll> &b) {
    return a.first * b.second < b.first * a.second;
  });
  ll ans = 0;
  for (int i = 1; i < num.size(); ++i) {
    ans += num[i - 1].first * num[i].second;
    num[i].first += num[i - 1].first;
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