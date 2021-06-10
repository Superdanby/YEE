#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &values) {
  vector<ll> dp(values.size());
  vector<bool> pushed(values.size());
  queue<ll> que;
  que.push(0);
  while (!que.empty()) {
    ll node = que.front();
    que.pop();
    ll flip = 1, next;
    while (flip < values.size()) {
      next = node | flip;
      if (next > node)
        dp[next] = dp[node] + values[node] > dp[next] ? dp[node] + values[node]
                                                      : dp[next];
      if (!pushed[next]) {
        pushed[next] = true;
        que.push(next);
      }
      flip <<= 1;
    }
  }

  return dp.back() + values.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll power;
  cin >> power;
  ll size = 1;
  for (int i = 0; i < power; ++i) size <<= 1;
  vector<ll> values(size);
  for (auto &x : values) cin >> x;
  cout << solve(values) << "\n";

  return 0;
}
