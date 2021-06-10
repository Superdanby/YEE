#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

pair<ll, ll> solve(priority_queue<ll, vector<ll>, greater<ll>> &pq) {
  ll ans = 0;
  while (pq.size() > 1) {
    ll fir = pq.top();
    pq.pop();
    ll sec = pq.top();
    pq.pop();
    ans += fir + sec;
    pq.push(fir + sec);
  }
  return {pq.top(), ans};
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  priority_queue<ll, vector<ll>, greater<ll>> pq;
  int inp;
  while (nums--) {
    cin >> inp;
    pq.push(inp);
  }

  auto ans = solve(pq);
  cout << ans.first << "\n" << ans.second << "\n";

  return 0;
}