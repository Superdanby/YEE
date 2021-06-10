#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const vector<ll> &nums, const int coverage) {
  priority_queue<pair<ll, ll>, vector<pair<ll, ll>>, greater<pair<ll, ll>>>
      pq;  // cost, index
  pq.push({0, -coverage - 1});
  for (int i = 0; i < nums.size(); ++i) {
    while (pq.top().second + coverage * 2 < i - 1) {
      // cerr << pq.top().first << "\n";
      pq.pop();  // pq should not be empty
    }
    pq.push({pq.top().first + nums[i], i});
  }
  while (pq.top().second + coverage + 1 < nums.size())
    pq.pop();  // pq should not be empty
  return pq.top().first;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt, coverage;
  cin >> num_cnt >> coverage;

  vector<ll> nums(num_cnt);
  for (auto &x : nums) cin >> x;

  cout << solve(nums, coverage) << "\n";

  return 0;
}
