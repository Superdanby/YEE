#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

ll solve(vector<int> &num, const int length) {
  deque<ll> MAX, MIN;
  ll ans = 0;
  for (int i = 0; i < num.size(); ++i) {
    if (!MAX.empty() && i - MAX.front() == length) MAX.pop_front();
    if (!MIN.empty() && i - MIN.front() == length) MIN.pop_front();
    while (!MAX.empty() && num[MAX.back()] < num[i]) MAX.pop_back();
    while (!MIN.empty() && num[MIN.back()] > num[i]) MIN.pop_back();
    MAX.push_back(i);
    MIN.push_back(i);
    ans = ans < num[MAX.front()] - num[MIN.front()]
              ? num[MAX.front()] - num[MIN.front()]
              : ans;
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
