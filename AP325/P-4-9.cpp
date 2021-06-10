#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(set<ll> &num, const int servers) {
  ll lb = -1, ans = *(num.rbegin());
  while (ans - lb > 1) {
    ll pivot = (ans + lb) / 2;
    if ([&]() {
          ll end = -1, cnt = 0;
          for (const auto &x : num) {
            if (x > end) {
              if (cnt == servers) return false;
              ++cnt;
              end = x + pivot;
            }
          }
          return true;
        }())
      ans = pivot;
    else
      lb = pivot;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums, servers;
  cin >> nums >> servers;
  set<ll> num;
  int inp;
  while (nums--) {
    cin >> inp;
    num.insert(inp);
  }

  cout << solve(num, servers) << "\n";

  return 0;
}
