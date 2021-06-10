#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
constexpr const ll MAX = 1e18;

ll solve(const string& cypher, ll& side) {
  ll ans = 0;
  stack<int> depth;
  depth.push(0);
  for (auto& x : cypher) {
    ++depth.top();
    // cerr << x << ": " << side << "\n";
    if (x == '2') {
      side >>= 1;
      depth.push(0);
    } else if (x == '1') {
      ans += side * side;
    }
    while (depth.top() == 4) {
      depth.pop();
      side <<= 1;
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  string inp;
  ll side;
  cin >> inp >> side;
  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(inp, side) << "\n";

  return 0;
}
