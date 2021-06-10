#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

ll solve(string x, ll y, ll p) {
  ll base = 0;
  for (const auto& z : x) base = (base * 10 + z - '0') % p;
  int exp = 1;
  ll ans = 1;
  while (y >= exp) {
    if (exp & y) ans = ans * base % p;
    base = base * base % p;
    exp <<= 1;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {

  string x;
  ll y, p;
  cin >> x >> y >> p;

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(x, y, p) << "\n";

  return 0;
}
