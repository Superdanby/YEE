#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(vector<vector<ll>> &nums) {
  // prefix sum
  for (int i = 1; i < nums.size(); ++i)
    for (int j = 1; j < nums[i].size(); ++j) nums[i][j] += nums[i][j - 1];
  for (int j = 1; j < nums.front().size(); ++j)
    for (int i = 1; i < nums.size(); ++i) nums[i][j] += nums[i - 1][j];

  // for (const auto &x : nums) {
  //   for (const auto &y : x) cerr << y << " ";
  //   cerr << "\n";
  // }

  ll ans = 0;
  for (int i = 1; i < nums.size(); ++i) {  // row upper bound
    for (int j = 0; j < i; ++j) {          // row lower bound
      for (int k = 1, l = 0; k < nums[i].size();
           ++k) {  // snake crawling on column
        ll value = (nums[i][k] - nums[j][k]) - (nums[i][l] - nums[j][l]);
        if (value < 0) {
          l = k;
          continue;
        }
        ans = value > ans ? value : ans;
      }
    }
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll rows, cols;
  cin >> rows >> cols;
  vector<vector<ll>> nums(
      rows + 1, vector<ll>(cols + 1));  // Pad first row & first column with 0s
  for (int i = 1; i < nums.size(); ++i)
    for (int j = 1; j < nums[i].size(); ++j) cin >> nums[i][j];

  cout << solve(nums) << "\n";

  return 0;
}
