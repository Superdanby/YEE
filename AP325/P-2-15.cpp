#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

int solve(vector<ll> &point, vector<ll> &key) {
  for (int i = 1; i < point.size(); ++i) point[i] += point[i - 1];
  // for (auto &x : point) cerr << x << " ";
  // cerr << "point \n";
  int start = point.size() - 1;
  for (auto &x : key) {
    x += point[start];
    x %= point.back();
    auto it = lower_bound(point.begin(), point.end(), x);
    start = (it - point.begin()) % point.size();
    // cerr << start << "s";
  }
  return start % point.size() + 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int points, keys;
  cin >> points >> keys;

  vector<ll> point(points), key(keys);
  for (auto &x : point) cin >> x;
  for (auto &x : key) cin >> x;
  cout << solve(point, key) << "\n";

  return 0;
}
