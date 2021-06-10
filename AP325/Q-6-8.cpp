#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(const string str1, const string str2) {
  vector<vector<ll>> dp(str1.length() + 1, vector<ll>(str2.length() + 1));
  ll ans = 0;
  for (int i = 1; i < dp.size(); ++i)
    for (int j = 1; j < dp[i].size(); ++j) {
      ll points =
          (dp[i][j - 1] > dp[i - 1][j] ? dp[i][j - 1] : dp[i - 1][j]) - 3;
      if (str1[i - 1] == str2[j - 1])
        dp[i][j] =
            dp[i - 1][j - 1] + 8 > points ? dp[i - 1][j - 1] + 8 : points;
      else
        dp[i][j] =
            dp[i - 1][j - 1] - 5 > points ? dp[i - 1][j - 1] - 5 : points;
      dp[i][j] = dp[i][j] > 0 ? dp[i][j] : 0;
      ans = dp[i][j] > ans ? dp[i][j] : ans;
    }

  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << y << " ";
  //   cerr << "\n";
  // }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string str1, str2;
  cin >> str1 >> str2;

  cout << solve(str1, str2) << "\n";

  return 0;
}
