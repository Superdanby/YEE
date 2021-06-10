#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 62;

ll solve(vector<pair<ll, ll>> &num) {
  unordered_set<ll> cnt_x, cnt_y;
  for (const auto &x : num) {
    cnt_x.insert(x.first);
    cnt_y.insert(x.second);
  }
  bool axis = cnt_x.size() > cnt_y.size() ? 0 : 1;
  if (axis == 0) {
    sort(num.begin(), num.end(),
         [&](const pair<ll, ll> &a, const pair<ll, ll> &b) {
           if (a.first == b.first) return a.second < b.second;
           return a.first < b.first;
         });
  } else if (axis == 1) {
    sort(num.begin(), num.end(),
         [&](const pair<ll, ll> &a, const pair<ll, ll> &b) {
           if (a.second == b.second) return a.first < b.first;
           return a.second < b.second;
         });
  }
  ll ans = INF;
  if (axis == 0) {
    for (auto back = num.begin(), front = num.begin(); back != num.end();
         ++back) {
      while (back->first - ans > front->first) ++front;
      // ++front, cerr << front->first << "\n";
      ++back;
      for (auto it = front; it != back; ++it) {
        auto it_sec = it;
        for (++it_sec; it_sec != back; ++it_sec) {
          ll abs_x = it_sec->first > it->first ? it_sec->first - it->first
                                               : it->first - it_sec->first;
          ll abs_y = it_sec->second > it->second ? it_sec->second - it->second
                                                 : it->second - it_sec->second;
          ans = abs_x + abs_y < ans ? abs_x + abs_y : ans;
        }
      }
      --back;
    }
  } else if (axis == 1) {
    for (auto back = num.begin(), front = num.begin(); back != num.end();
         ++back) {
      while (back->second - ans > front->second) ++front;
      // ++front, cerr << front->second << "\n";
      ++back;
      for (auto it = front; it != back; ++it) {
        auto it_sec = it;
        for (++it_sec; it_sec != back; ++it_sec) {
          ll abs_x = it_sec->first > it->first ? it_sec->first - it->first
                                               : it->first - it_sec->first;
          ll abs_y = it_sec->second > it->second ? it_sec->second - it->second
                                                 : it->second - it_sec->second;
          ans = abs_x + abs_y < ans ? abs_x + abs_y : ans;
        }
      }
      --back;
    }
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<pair<ll, ll>> num(nums);
  for (auto &x : num) cin >> x.first >> x.second;

  cout << solve(num) << "\n";

  return 0;
}