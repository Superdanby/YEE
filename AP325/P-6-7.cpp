#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(const string &str1, const string &str2) {
  vector<vector<ll>> nums(str1.size() + 1, vector<ll>(str2.size() + 1));
  ll ans = 0;
  for (int i = 1; i < nums.size(); ++i)
    for (int j = 1; j < nums[i].size(); ++j) {
      nums[i][j] =
          nums[i][j - 1] > nums[i - 1][j] ? nums[i][j - 1] : nums[i - 1][j];
      if (str1[i - 1] == str2[j - 1])
        nums[i][j] = nums[i - 1][j - 1] + 1 > nums[i][j]
                         ? nums[i - 1][j - 1] + 1
                         : nums[i][j];
    }
  return nums.back().back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string str1, str2;
  cin >> str1 >> str2;
  cout << solve(str1, str2) << "\n";

  return 0;
}
