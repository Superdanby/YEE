#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

ll solve(vector<pair<ll, ll>> &items, const ll limit) {
  vector<ll> dp(limit + 1);
  for (int i = 0; i < items.size(); ++i)
    for (int j = limit; j >= items[i].first; --j)
      dp[j] = dp[j - items[i].first] + items[i].second > dp[j]
                  ? dp[j - items[i].first] + items[i].second
                  : dp[j];
  return dp.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll item_cnt, limit;
  cin >> item_cnt >> limit;
  vector<pair<ll, ll>> items(item_cnt);  // weight, value
  for (auto &x : items) cin >> x.first;
  for (auto &x : items) cin >> x.second;
  cout << solve(items, limit) << "\n";

  return 0;
}