#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &w, vector<ll> &l) {
  sort(w.begin(), w.end(), greater<ll>());
  sort(l.begin(), l.end(), greater<ll>());
  int i = 0;
  for (int j = 0; j < l.size(); ++j) {
    if (w[i] > l[j]) ++i;
  }
  return i;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<ll> w(nums), l(nums);
  for (auto &x : l) cin >> x;
  for (auto &x : w) cin >> x;

  cout << solve(w, l) << "\n";

  return 0;
}
