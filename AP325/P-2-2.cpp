#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int nums;
  cin >> nums;
  vector<int> inp(nums);
  map<int, int> dict;
  for (auto &x : inp) {
    cin >> x;
    dict[x] = 0;
  }

  int cnt = -1;
  for (auto &x : dict) x.second = ++cnt;

  auto it = inp.begin();
  cout << dict[*it];
  for (++it; it != inp.end(); ++it) cout << " " << dict[*it];

  cout << "\n";

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";

  return 0;
}
