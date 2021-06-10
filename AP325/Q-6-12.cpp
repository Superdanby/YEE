#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 1e9 + 9;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &nums, const int days) {
  priority_queue<pair<ll, ll>> pq;  // best value, i: best value on day i
  vector<ll> best(nums.size());
  pq.push({0, -days});
  for (int i = 0; i < nums.size(); ++i) {
    while (pq.top().second < i - days) pq.pop();
    best[i] = pq.top().first;
    // cerr << pq.top().first << " " << pq.top().second << "\n";
    if (i - days - 1 >= 0)
      best[i] = best[i - days - 1] + nums[i] > best[i]
                    ? best[i - days - 1] + nums[i]
                    : best[i];
    else
      best[i] = nums[i] > best[i] ? nums[i] : best[i];
    if (i - 1 > 0) best[i] = best[i - 1] > best[i] ? best[i - 1] : best[i];
    pq.push({best[i], i});
  }
  // for (const auto &x : best) cerr << x << " ";
  // cerr << "\n";
  return best.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num_cnt, days;
  cin >> num_cnt >> days;
  vector<int> nums(num_cnt);
  for (auto &x : nums) cin >> x;
  cout << solve(nums, days) << "\n";

  return 0;
}
