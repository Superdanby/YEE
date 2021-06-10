#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num, const int buckets) {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  for (int i = 0; i < buckets; ++i) pq.push(0);
  for (const auto &x : num) {
    auto finish = pq.top();
    pq.pop();
    pq.push(finish + x);
  }
  while (pq.size() != 1) pq.pop();

  return pq.top();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums, buckets;
  cin >> nums >> buckets;
  vector<ll> num(nums);
  for (auto &x : num) cin >> x;

  cout << solve(num, buckets) << "\n";

  return 0;
}
