#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(vector<vector<int>> &dist, const int start) {  // 0-index
  unordered_map<int, int> dict;
  for (int i = 0; i < dist.size(); ++i) dict[1 << i] = i;
  vector<vector<int>> dp(1 << dist.size(), vector<int>(dist.size(), INF));
  vector<vector<bool>> qued(1 << dist.size(), vector<bool>(dist.size(), false));
  int state = 1 << start, MAX = 1 << dist.size();
  dp[state][start] = 0;
  queue<pair<int, int>> que;  // state, ending
  que.push({state, state});
  while (!que.empty()) {  // O(2^n)
    auto x = que.front();
    que.pop();
    int state = x.first, ending = x.second;
    // cerr << "\n\n" << state << " " << ending << "\n";
    for (int next_ending = 1; next_ending < MAX; next_ending <<= 1) {  // O(n)
      if ((state | next_ending) > state) {
        // cerr << (state | next_ending) << " " << state + next_ending << " "
        //      << next_ending << "          ";
        dp[state + next_ending][dict[next_ending]] =
            dp[state][dict[ending]] + dist[dict[ending]][dict[next_ending]] <
                    dp[state + next_ending][dict[next_ending]]
                ? dp[state][dict[ending]] +
                      dist[dict[ending]][dict[next_ending]]
                : dp[state + next_ending][dict[next_ending]];
        if (!qued[state + next_ending][dict[next_ending]]) {
          que.push({state + next_ending, next_ending});
          qued[state + next_ending][dict[next_ending]] = true;
        }
      }
    }
  }
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << setw(15) << y << " ";
  //   cerr << "\n";
  // }
  int ans = INF;
  for (int i = 0; i < dist.size(); ++i) {
    if (i == start) continue;
    ans = dp[MAX - 1][i] + dist[i][start] < ans
              ? dp[MAX - 1][i] + dist[i][start]
              : ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll city_cnt, start;
  cin >> city_cnt >> start;
  vector<vector<int>> dist(city_cnt, vector<int>(city_cnt));
  for (auto &x : dist)
    for (auto &y : x) cin >> y;
  cout << solve(dist, start) << "\n";

  return 0;
}
