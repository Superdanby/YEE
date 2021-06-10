#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num, const int tries) {
  int ans = 0;
  for (const auto &x : num) ans += x;
  int lb = -1;
  while (ans - lb > 1) {
    int pivot = (ans + lb) / 2;
    if ([&]() {
          int fuel = pivot;
          int loc_tries = tries;
          for (const auto &x : num) {
            if (fuel - x < 0) {
              if (loc_tries == 0 || pivot - x < 0) return false;
              --loc_tries;
              fuel = pivot - x;
            } else
              fuel -= x;
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

  int nums, tries;
  cin >> nums >> tries;
  vector<ll> num(nums);
  for (auto &x : num) cin >> x;

  cout << solve(num, tries) << "\n";

  return 0;
}
