#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

ll solve(unordered_set<ll> &ms, unordered_set<ll> &ns, ll k) {
  if (ms.size() > ns.size()) ms.swap(ns);
  if (ms.empty() && ns.find(k) != ns.end()) return 1;
  ll ans = 0;
  for (const auto &x : ms) {
    if (ns.find(k - x) != ns.end()) ++ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  ll target, inps;
  cin >> target >> inps;
  unordered_map<ll, ll> dict;
  string inp;
  target = (1 << target) - 1;
  while (inps--) {
    cin >> inp;
    ll num = 0;
    for (const auto &x : inp) {
      num |= (1 << (x - 'A'));
    }
    if (dict.find(num) == dict.end())
      dict[num] = 1;
    else
      ++dict[num];
  }
  ll ans = 0;
  for (const auto &x : dict) {
    if (dict.find(target - x.first) != dict.end()) {
      ans += dict[target - x.first] * x.second;
    }
  }

  cout << ans / 2 << "\n";

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";

  return 0;
}
