#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &num, const int length) {
  vector<int> cnt(num.size());
  ll colors = 0;
  for (int i = 0; i < length; ++i) {
    if (cnt[num[i]] == 0) ++colors;
    ++cnt[num[i]];
  }
  ll ans = colors;
  for (int i = length; i < num.size(); ++i) {
    if (cnt[num[i]] == 0) ++colors;
    ++cnt[num[i]];
    if (cnt[num[i - length]] == 1) --colors;
    --cnt[num[i - length]];
    ans = colors > ans ? colors : ans;
  }

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums, length;
  cin >> nums >> length;
  vector<int> num(nums);

  for (auto &x : num) cin >> x;

  cout << solve(num, length) << "\n";
  return 0;
}
