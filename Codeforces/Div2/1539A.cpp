#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases;
  ll cnt, interval, duration;
  while (cases--) {
    cin >> cnt >> interval >> duration;
    ll limit = duration / interval;
    if (!cnt) {
      cout << "0\n";
      continue;
    }
    if (cnt <= limit)
      cout << cnt * (cnt - 1) / 2 << "\n";
    else
      cout << limit * (limit - 1) / 2 + (cnt - limit) * limit << "\n";
  }
  return 0;
}