#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int item_cnt;
  cin >> item_cnt;
  vector<pair<ll, ll>> items(item_cnt);  // need, discount
  for (auto &x : items) cin >> x.first >> x.second;

  sort(items.begin(), items.end(),
       [](const pair<ll, ll> &a, const pair<ll, ll> &b) {
         if (a.second < b.second) return true;
         return false;
       });

  ll buy_cnt = 0, ans = 0;
  int front = 0, back = items.size() - 1;
  while (front <= back) {
    if (buy_cnt >= items[front].second) {
      buy_cnt += items[front].first;
      ans += items[front].first;
      ++front;
      continue;
    }
    if (buy_cnt + items[back].first <= items[front].second) {
      buy_cnt += items[back].first;
      ans += items[back].first * 2;
      --back;
      continue;
    } else {
      if (items[back].first >= items[front].second - buy_cnt) {
        items[back].first -= items[front].second - buy_cnt;
        ans += (items[front].second - buy_cnt) * 2;
        buy_cnt = items[front].second;
      } else {
        ans += items[back].first * 2;
        buy_cnt += items[back].first;
        --back;
      }
    }
  }

  cout << ans << "\n";
  return 0;
}