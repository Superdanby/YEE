#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int pairs;
  cin >> pairs;
  vector<pair<ll, ll>> action;
  while (pairs--) {
    ll val, start, stop;
    cin >> val >> start >> stop;
    action.emplace_back(make_pair(start, val));
    action.emplace_back(make_pair(stop + 1, -val));
  }
  sort(action.begin(), action.end());
  ll value = 0, ans = 0;
  for (size_t i = 0; i < action.size(); ++i) {
    value += action[i].second;
    ans = value > ans ? value : ans;
  }

  cout << ans << "\n";

  return 0;
