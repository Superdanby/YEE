#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &num, int target) {
  unordered_map<int, int> dict;
  ll ans = 0;
  for (int i = 0, front = 0; i < num.size(); ++i) {
    if (dict.find(num[i]) == dict.end())
      dict[num[i]] = 1;
    else
      ++dict[num[i]];

    if (dict[num[i]] == 1) {
      --target;
    } else {
      ++target;
      while (dict[num[i]] != 1) {
        --dict[num[front]];
        if (dict[num[front]] == 1)
          --target;
        else
          ++target;
        ++front;
      }
    }

    if (target == 0) ++ans;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int target, nums;
  cin >> target >> nums;
  vector<int> num(nums);

  for (auto &x : num) cin >> x;

  cout << solve(num, target) << "\n";
  return 0;
}
