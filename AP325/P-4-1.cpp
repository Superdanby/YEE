#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<ll, ll>> &line, vector<ll> &coor, int front, int end,
         int lfront, int lend) {
  if (front > end) return 0;
  int point = (front + end) / 2;
  int lans = lfront;
  for (int i = lfront + 1; i <= lend; ++i) {
    if (line[lans].first * coor[point] + line[lans].second <
        line[i].first * coor[point] + line[i].second)
      lans = i;
  }
  ll ans = line[lans].first * coor[point] + line[lans].second;
  ans += solve(line, coor, front, point - 1, lfront, lans);
  ans += solve(line, coor, point + 1, end, lans, lend);
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases;
  vector<int> coins{50, 10, 5, 1};
  while (cases--) {
    int num;
    cin >> num;
    int ans = 0;
    for (int i = 0; i < coins.size(); ++i) {
      ans += num / coins[i];
      num %= coins[i];
    }
    cout << ans << "\n";
  }

  return 0;
}
