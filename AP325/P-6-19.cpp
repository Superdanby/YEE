#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const ll num) {
  ll base = 10;
  vector<ll> digits;
  ll temp = num;
  while (temp) {
    digits.push_back(temp % base);
    temp /= base;
  }
  // for (const auto &x : digits) cerr << x << " ";
  // cerr << "\n";
  vector<vector<vector<ll>>> dp(
      digits.size(),
      vector<vector<ll>>(base, vector<ll>(2)));  // digit, 0 ~ 9, restricted
  for (int i = 1; i < base; ++i) dp.front()[i][0] = 1;
  dp.front()[digits.front()][1] = 1;
  vector<ll> wildcard(digits.size());
  for (int i = 1; i < dp.size(); ++i) {
    // unrestricted
    for (int j = 1; j < dp[i].size(); ++j) {
      for (int k = j; k < base; ++k) dp[i][j][0] += dp[i - 1][k][0];
    }

    // restricted
    for (int k = digits[i]; k < digits[i - 1]; ++k)
      dp[i][digits[i]][1] += dp[i - 1][k][0];

    if (digits[i - 1] >= digits[i])
      dp[i][digits[i]][1] += dp[i - 1][digits[i - 1]][1];

    // wildcard
    for (int k = 1; k < base; ++k) wildcard[i] += dp[i - 1][k][0];
    wildcard[i] += wildcard[i - 1];
  }
  ll ans = 0;
  ans += wildcard.back();
  for (int i = 1; i < digits.back(); ++i) ans += dp.back()[i][0];
  ans += dp.back()[digits.back()][1];
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num;
  cin >> num;
  cout << solve(num) << "\n";

  return 0;
}
