#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

inline ll get_minor(vector<vector<int>> &nums, int ax, int ay, int bx, int by) {
  ll zeros = 0, ones = 0;
  if (ax == bx) {
    for (int i = ay; i <= by; ++i) {
      if (nums[ax][i])
        ++ones;
      else
        ++zeros;
    }
  } else {
    for (int i = ax; i <= bx; ++i) {
      if (nums[i][ay])
        ++ones;
      else
        ++zeros;
    }
  }
  return ones < zeros ? ones : zeros;
}

ll solve(vector<vector<int>> &nums, vector<vector<vector<vector<int>>>> &state,
         int ax, int ay, int bx, int by) {
  if (state[ax][ay][bx][by] != 0x3f3f3f3f) return state[ax][ay][bx][by];
  if (bx - ax < 1 || by - ay < 1) {
    return state[ax][ay][bx][by] = 0;
  }
  ll ans = INF;
  auto up =
      get_minor(nums, ax, ay, ax, by) + solve(nums, state, ax + 1, ay, bx, by);
  auto down =
      get_minor(nums, bx, ay, bx, by) + solve(nums, state, ax, ay, bx - 1, by);
  auto left =
      get_minor(nums, ax, ay, bx, ay) + solve(nums, state, ax, ay + 1, bx, by);
  auto right =
      get_minor(nums, ax, by, bx, by) + solve(nums, state, ax, ay, bx, by - 1);
  ans = up < ans ? up : ans;
  ans = down < ans ? down : ans;
  ans = left < ans ? left : ans;
  ans = right < ans ? right : ans;

  // cerr << ax << " " << ay << "\t" << bx << " " << by << ": " << ans << "\n";

  return state[ax][ay][bx][by] = ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll rows, cols;
  cin >> rows >> cols;
  vector<vector<int>> nums(rows, vector<int>(cols));
  for (auto &x : nums)
    for (auto &y : x) cin >> y;
  vector<vector<vector<vector<int>>>> state(
      rows,
      vector<vector<vector<int>>>(
          cols, vector<vector<int>>(rows, vector<int>(cols, 0x3f3f3f3f))));
  cout << solve(nums, state, 0, 0, rows - 1, cols - 1) << "\n";

  return 0;
}