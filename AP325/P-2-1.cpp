
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

void solve(vector<int> &num) {
  set<int> ans;
  for (const auto &x : num) ans.insert(x);
  cout << ans.size() << "\n";
  auto it = ans.begin();
  cout << *it++;
  for (; it != ans.end(); ++it) cout << " " << *it;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int nums;
  cin >> nums;
  vector<int> num(nums);

  for (auto &x : num) cin >> x;

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  solve(num);

  return 0;
}
