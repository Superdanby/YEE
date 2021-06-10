#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<ll> &num) {
  ll ans = 0;
  int front = -1;
  unordered_set<ll> dict;
  for (const auto &x : num) {
    if (dict.find(x) == dict.end())
      dict.insert(x);
    else {
      ans = dict.size() > ans ? dict.size() : ans;
      while (num[++front] != x) {
        dict.erase(num[front]);
      }
    }
  }

  return dict.size() > ans ? dict.size() : ans;
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
