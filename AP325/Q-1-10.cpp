#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

int solve(vector<vector<int>> &num, vector<pair<int, int>> &loc, int row) {
  int ret = 0;
  for (const auto &x : loc) ret += num[x.first][x.second];

  if (row == num.size()) {
    return ret;
  }

  for (int i = 0; i < num[row].size(); ++i) {
    bool ok = true;
    for (const auto &x : loc)
      if (x.second == i || row - x.first == i - x.second ||
          row - x.first == x.second - i) {
        ok = false;
        break;
      }
    if (!ok) continue;
    loc.push_back(make_pair(row, i));
    auto val = solve(num, loc, row + 1);
    loc.pop_back();
    ret = ret > val ? ret : val;
  }
  auto val = solve(num, loc, row + 1);
  ret = ret > val ? ret : val;
  return ret;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int length;
  cin >> length;
  vector<vector<int>> num(length, vector<int>(length));
  for (auto &x : num)
    for (auto &y : x) cin >> y;

  vector<pair<int, int>> loc;  // (row, col)

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(num, loc, 0) << "\n";

  return 0;
}
