#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<pair<int, int>> &num, int target) {
  sort(num.begin(), num.end());
  deque<int> MAX, MIN;
  ll ans = 0;
  for (int i = 0; i < num.size(); ++i) {
    while (!MAX.empty() && num[i].first - num[MAX.front()].first > target)
      MAX.pop_front();
    while (!MIN.empty() && num[i].first - num[MIN.front()].first > target)
      MIN.pop_front();
    while (!MAX.empty() && num[MAX.back()].second < num[i].second)
      MAX.pop_back();
    while (!MIN.empty() && num[MIN.back()].second > num[i].second)
      MIN.pop_back();
    MAX.push_back(i);
    MIN.push_back(i);
    ans = num[MAX.front()].second - num[MIN.front()].second > ans
              ? num[MAX.front()].second - num[MIN.front()].second
              : ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums, target;
  cin >> nums >> target;
  vector<pair<int, int>> coor(nums);

  for (auto &x : coor) cin >> x.first;
  for (auto &x : coor) cin >> x.second;

  cout << solve(coor, target) << "\n";
  return 0;
}
