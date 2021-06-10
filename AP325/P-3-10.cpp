#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &num) {
  ll ans = 2147483647;
  unordered_map<int, int> dict;
  int front = 0;
  for (int i = 0; i < num.size(); ++i) {
    if (dict.find(num[i]) == dict.end()) {
      dict[num[i]] = 1;
      ans = 2147483647;
    } else
      ++dict[num[i]];

    while (dict[num[front]] > 1) {
      --dict[num[front]];
      ++front;
    }
    ans = i - front + 1 < ans ? i - front + 1 : ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int nums;
  cin >> nums;
  vector<int> num(nums);

  for (auto &x : num) cin >> x;

  cout << solve(num) << "\n";
  return 0;
}
