#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(vector<vector<ll>> &nums) {
  nums[0][1] = nums[1][0] = 0;
  for (int i = 1; i < nums.size(); ++i)
    for (int j = 1; j < nums[i].size(); ++j)
      nums[i][j] +=
          nums[i - 1][j] > nums[i][j - 1] ? nums[i - 1][j] : nums[i][j - 1];
  return nums.back().back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int rows, cols;
  cin >> rows >> cols;
  vector<vector<ll>> nums(rows + 1, vector<ll>(cols + 1, -INF));
  for (int i = 1; i < nums.size(); ++i)
    for (int j = 1; j < nums[i].size(); ++j) cin >> nums[i][j];
  cout << solve(nums) << "\n";

  return 0;
}
