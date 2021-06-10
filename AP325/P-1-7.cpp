#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const ll MOD = 1e9 + 7;
constexpr const int MOD = 10009;
// constexpr const int MAX = 2147483647;
// constexpr const int MAX = 0x3f3f3f3f;
constexpr const ll MAX = 1e18;

ll solve(vector<int> &num) {
  unordered_map<int, int> dict, temp;
  dict[1] = 1;
  for (const auto &x : num) {
    for (const auto &y : dict) {
      int val = y.first * x % MOD;
      if (temp.find(val) == temp.end())
        temp[val] = y.second;
      else
        temp[val] += y.second;
    }
    for (const auto &y : temp)
      if (dict.find(y.first) == dict.end())
        dict[y.first] = y.second;
      else
        dict[y.first] += y.second;
    temp.clear();
  }
  return dict[1] - 1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int nums;
  cin >> nums;
  vector<int> num(nums);
  for (auto &x : num) cin >> x;

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(num) << "\n";

  return 0;
}

// Slow
// #include <bits/stdc++.h>

// using namespace std;

// typedef long long ll;

// // constexpr const ll MOD = 1e9 + 7;
// constexpr const int MOD = 10009;
// // constexpr const int MAX = 2147483647;
// // constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

// ll solve(vector<int> &num, size_t &&i, int &&mod) {
//   // cerr << i << " " << mod << "\n";
//   mod %= MOD;
//   if (i == num.size()) return mod == 1 ? 1 : 0;
//   return solve(num, i + 1, forward<int>(mod)) + solve(num, i + 1, mod * num[i]);
// }

// int main() {
//   ios_base::sync_with_stdio(false);
//   cin.tie(0);

//   // int cases;
//   // cin >> cases;
//   // while (cases--) {
//   int nums;
//   cin >> nums;
//   vector<int> num(nums);
//   for (auto &x : num) cin >> x;

//   // }
//   // for (const auto &x : cut) cout << x << " ";
//   // cout << "\n";
//   cout << solve(num, 0, 1) - 1 << "\n";

//   return 0;
// }
