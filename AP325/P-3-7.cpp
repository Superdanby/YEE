#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

pair<ll, ll> solve(vector<int> &num, int target) {
  ll ans = -1, cnt = 1;
  ll accumulate = 0;
  for (int i = 0, front = 0; i < num.size(); ++i) {
    while (accumulate + num[i] > target) {
      accumulate -= num[front];
      ++front;
    }
    accumulate += num[i];
    // cerr << accumulate << " ";
    if (ans == accumulate)
      ++cnt;
    else if (ans < accumulate) {
      ans = accumulate;
      cnt = 1;
    }
  }

  return pair<ll, ll>(ans, cnt);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums, target;
  cin >> nums >> target;
  vector<int> num(nums);

  for (auto &x : num) cin >> x;

  auto ans = solve(num, target);
  cout << ans.first << "\n" << ans.second << "\n";
  return 0;
}
