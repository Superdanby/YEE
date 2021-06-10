#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;
int get_cost(vector<vector<int>> &num, int rs, int re, int cs, int ce) {
  // cout << rs << " " << re << "  " << cs << " " << ce << "\n";
  int cnt0 = 0, cnt1 = 0;
  if (re == -1) {
    for (int i = cs; i < ce; ++i)
      if (num[rs][i] == 1) {
        ++cnt1;
      } else {
        ++cnt0;
      }
  } else {
    for (int i = rs; i < re; ++i)
      if (num[i][cs] == 1) {
        ++cnt1;
      } else {
        ++cnt0;
      }
  }
  return cnt0 < cnt1 ? cnt0 : cnt1;
}

int solve(vector<vector<int>> &num, pair<int, int> front, pair<int, int> end) {
  // cout << front.first << " " << front.second << "  " << end.first << " "
  //      << end.second << "\n";
  if (end.first <= front.first && end.second <= front.second) {
    return 0;
  }
  int min_sub = MAX, cost;
  if (front.first < end.first) {
    cost = get_cost(num, front.first, -1, front.second, end.second) +
           solve(num, make_pair(front.first + 1, front.second), end);
    min_sub = min_sub < cost ? min_sub : cost;
  }
  if (front.second < end.second) {
    cost = get_cost(num, front.first, end.first, front.second, -1) +
           solve(num, make_pair(front.first, front.second + 1), end);
    min_sub = min_sub < cost ? min_sub : cost;
  }
  if (front.first < end.first) {
    cost = get_cost(num, end.first - 1, -1, front.second, end.second) +
           solve(num, front, make_pair(end.first - 1, end.second));
    min_sub = min_sub < cost ? min_sub : cost;
  }
  if (front.second < end.second) {
    cost = get_cost(num, front.first, end.first, end.second - 1, -1) +
           solve(num, front, make_pair(end.first, end.second - 1));
    min_sub = min_sub < cost ? min_sub : cost;
  }
  return min_sub;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int rows, cols;
  cin >> rows >> cols;
  vector<vector<int>> num(rows, vector<int>(cols));
  for (auto &x : num)
    for (auto &y : x) cin >> y;

  pair<int, int> front(0, 0), end(rows, cols);  // row, col

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(num, front, end) << "\n";

  return 0;
}
