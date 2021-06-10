#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 62;

ll solve(const vector<ll> &time, const ll deadline) {
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  ll ans = time.size(), lb = 0;
  while (ans - lb > 1) {
    ll pivot = (ans + lb) / 2;
    for (ll i = 0; i < pivot; ++i) pq.push(0);
    for (const auto &x : time) {
      ll next = pq.top();
      pq.pop();
      pq.push(next + x);
    }
    while (pq.size() > 1) pq.pop();
    if (pq.top() <= deadline)
      ans = pivot;
    else
      lb = pivot;
    pq.pop();
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int customers;
  ll deadline;
  cin >> customers;
  cin >> deadline;
  vector<ll> time(customers);
  for (auto &x : time) cin >> x;

  cout << solve(time, deadline) << "\n";

  return 0;
}
