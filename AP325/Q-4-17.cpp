#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 62;

string solve(vector<pair<ll, ll>> &num) {
  sort(num.begin(), num.end());

  ll time = 0;
  for (const auto &x : num) {
    time += x.second;
    if (time > x.first) return "no";
  }

  return "yes";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases;
  while (cases--) {
    int nums;
    cin >> nums;
    vector<pair<ll, ll>> num(nums);
    for (auto &x : num) cin >> x.second;
    for (auto &x : num) cin >> x.first;

    cout << solve(num) << "\n";
  }

  return 0;
}
