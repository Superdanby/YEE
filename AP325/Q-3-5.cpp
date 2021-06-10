#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num, vector<ll> &stool) {
  vector<ll> steck(num.size());
  int end = 0;
  ll ans = 0;
  for (int i = 0; i < num.size(); ++i) {
    auto it = lower_bound(steck.begin(), steck.begin() + end, num[i] + stool[i],
                          [&num](ll a, ll b) { return num[a] > b; });
    if (it == steck.begin())
      ans += i;
    else
      ans += i - *(--it) - 1;
    it = lower_bound(steck.begin(), steck.begin() + end, num[i],
                     [&num](ll a, ll b) { return num[a] > b; });
    *it = i;
    end = it - steck.begin() + 1;
    // for (int i = 0; i < end; ++i) cerr << steck[i] << " ";
    // cerr << "\n";
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<ll> num(nums), stool(nums);
  for (auto &x : num) cin >> x;
  for (auto &x : stool) cin >> x;

  cout << solve(num, stool) << "\n";
  return 0;
}
