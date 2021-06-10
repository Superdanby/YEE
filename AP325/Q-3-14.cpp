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

  int nums, targets;
  cin >> nums >> targets;
  vector<pair<ll, ll>> line(nums);
  vector<ll> coor(targets);

  for (auto &x : line) cin >> x.first >> x.second;
  for (auto &x : coor) cin >> x;
  sort(coor.begin(), coor.end());
  sort(line.begin(), line.end());

  cout << solve(line, coor, 0, targets - 1, 0, nums - 1) << "\n";
  return 0;
}
