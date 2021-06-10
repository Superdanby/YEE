#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<ll, ll>> &seg) {
  ll ans = 0, end = -1, start = -1;
  sort(seg.begin(), seg.end());
  for (const auto &x : seg) {
    if (x.first > end) {
      ans += end - start;
      start = x.first;
    }
    end = end > x.second ? end : x.second;
  }
  ans += end - start;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int segments;
  cin >> segments;
  vector<pair<ll, ll>> seg(segments);
  for (auto &x : seg) cin >> x.first >> x.second;

  cout << solve(seg) << "\n";

  return 0;
}
