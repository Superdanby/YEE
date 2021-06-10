#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<pair<ll, int>, int>> &nums) {
  sort(
      nums.begin(), nums.end(),
      [](const pair<pair<ll, int>, int> &a, const pair<pair<ll, int>, int> &b) {
        if (a.first.second == b.first.second) return a.second < b.second;
        return a.first.second > b.first.second;
      });

  map<int, ll> dict;  // ending number, value
  dict.insert({-1, 0});
  ll ans = 0;
  for (const auto &x : nums) {
    auto it = dict.upper_bound(x.second);
    --it;
    ll value = it->second + x.first.first;
    ans = value > ans ? value : ans;
    if (it->first == x.second) {
      it->second = value;
    } else {
      it = dict.insert(it, {x.second, value});
    }
    ++it;
    while (it != dict.end() && it->second <= value) it = dict.erase(it);
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num_cnt;
  cin >> num_cnt;
  vector<pair<pair<ll, int>, int>> nums(num_cnt);
  for (auto &x : nums) cin >> x.first.first;
  for (auto &x : nums) cin >> x.first.second;
  for (auto &x : nums) cin >> x.second;
  cout << solve(nums) << "\n";

  return 0;
}
