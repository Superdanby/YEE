#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &height, vector<int> &weight) {
  map<int, ll> lower;                 // 1, 2, 3
  map<int, ll, greater<int>> higher;  // 7, 6, 5
  for (int i = 0; i < height.size(); ++i) {
    ll best = weight[i];
    auto ridge = higher.lower_bound(height[i]);
    if (ridge != higher.begin()) {
      --ridge;
      best += ridge->second;
    }

    // update higher
    auto land = lower.lower_bound(height[i]);
    if (land != lower.begin()) {
      --land;
      ridge = higher.find(height[i]);
      if (ridge == higher.end())
        ridge = higher.insert(ridge, {height[i], land->second});
      else
        higher[height[i]] =
            land->second > higher[height[i]] ? land->second : higher[height[i]];
      if (ridge != higher.begin()) {
        auto prev = ridge;
        --prev;
        if (prev->second >= ridge->second) ridge = higher.erase(ridge);
      }
      if (ridge != higher.end()) {
        auto next = ridge;
        ++next;
        while (next != higher.end() && ridge->second >= next->second)
          next = higher.erase(next);
      }
    }

    // update lower
    land = lower.find(height[i]);
    if (land == lower.end()) {
      land = lower.insert(land, {height[i], best});
    } else {
      land->second = best > land->second ? best : land->second;
    }
    if (land != lower.begin()) {
      auto prev = land;
      --prev;
      if (prev->second >= land->second) land = lower.erase(land);
    }
    if (land != lower.end()) {
      auto next = land;
      ++next;
      while (next != lower.end() && land->second >= next->second)
        next = lower.erase(next);
    }

    // cerr << "H: ";
    // for (const auto &x : higher)
    //   cerr << x.first << ": " << x.second << "       ";
    // cerr << "\n";
    // cerr << "L: ";
    // for (const auto &x : lower)
    //   cerr << x.first << ": " << x.second << "       ";
    // cerr << "\n\n";
  }
  return lower.rbegin()->second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt;
  cin >> num_cnt;
  vector<int> height(num_cnt), value(num_cnt);
  for (auto &x : height) cin >> x;
  for (auto &x : value) cin >> x;
  cout << solve(height, value) << "\n";

  return 0;
}
