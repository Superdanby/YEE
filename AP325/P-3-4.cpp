#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num) {
  vector<ll> prefix(num.size());
  prefix.front() = -1;
  for (int i = 1; i < prefix.size(); ++i) {
    int j = i - 1;
    while (j >= 0 && num[i] >= num[j]) j = prefix[j];
    prefix[i] = j;
  }
  ll ans = 0;

  for (int i = 0; i < prefix.size(); ++i) {
    ans += prefix[i] < 0 ? i + 1 : i - prefix[i];
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<ll> num(nums);
  for (auto &x : num) cin >> x;

  cout << solve(num) << "\n";
  return 0;
}
