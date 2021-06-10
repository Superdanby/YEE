#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

// x' = x^2 + 2y^2
// y' = 2xy
// s' = s * x + 2 * t * y
// y' = s * y + x * t
// s tr2, x yr2 = sx + 2ty
void solve(ll &x, ll &y, const ll n, ll &s, ll &t) {
  if (!n) {
    s = 1, t = 0;
    return;
  }
  ll filter = 1;
  s = 0, t = 0;
  while (filter <= n) {
    if (filter & n) {
      if (!s)
        s = x, t = y;
      else {
        ll _s = (s * x % MOD + 2 * (t * y % MOD) % MOD) % MOD;
        ll _t = (s * y % MOD + x * t % MOD) % MOD;
        s = _s, t = _t;
      }
    }
    filter <<= 1;
    ll _x = (x * x % MOD + 2 * (y * y % MOD) % MOD) % MOD;
    ll _y = 2 * (x * y % MOD) % MOD;
    x = _x, y = _y;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll x, y, n, s, t;
  cin >> x >> y >> n;
  solve(x, y, n, s, t);
  cout << s << " " << t << "\n";

  return 0;
}
