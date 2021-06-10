#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

ll extgcd(ll a, ll b, ll &x, ll &y) {
  if (b == 0) {
  	x = 1, y = 0;
  	return a;
  }
  ll ret = extgcd(b, a % b, y, x);
  y -= a / b * x;
  return ret;
  
}
void solve(ll &a) {
  ll x, y;
  extgcd(a, MOD, x, y);
  //a = x;
  a = x < 0 ? x + MOD : x;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases >> MOD;
  vector<ll> inp(cases);
  for (auto & x : inp) {
    cin >> x;
    solve(x);
  }
  auto it = inp.begin();
  cout << *it;
  for (++it; it != inp.end(); ++it) {
    cout << " " << *it;
  }
  // while (cases--) {
  // }
  cout << "\n";

  return 0;
}
