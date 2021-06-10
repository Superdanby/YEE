#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;

ll solve(vector<double> &cut, int left, int right) {
  if (right - left == 1) return 0;
  double mid = (cut[left] + cut[right]) / 2;
  int idx =
      lower_bound(cut.begin() + left, cut.begin() + right, mid) - cut.begin();
  // cerr << left << " " << idx << " " << right << "\n";
  if (idx - 1 == left)
    return solve(cut, left, idx) + solve(cut, idx, right) +
           ll(cut[right] - cut[left]);
  else if (idx == right)
    return solve(cut, left, idx - 1) + solve(cut, idx - 1, right) +
           ll(cut[right] - cut[left]);
  else if (cut[idx] - mid < mid - cut[idx - 1])
    return solve(cut, left, idx) + solve(cut, idx, right) +
           ll(cut[right] - cut[left]);
  else
    return solve(cut, left, idx - 1) + solve(cut, idx - 1, right) +
           ll(cut[right] - cut[left]);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  int cuts;
  double left = 0, right;
  cin >> cuts >> right;
  vector<double> cut(cuts + 1);
  auto it = cut.begin();
  for (++it; it != cut.end(); ++it) cin >> (*it);
  cut.front() = 0;
  cut.push_back(right);
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";
  cout << solve(cut, 0, cut.size() - 1) << "\n";

  return 0;
}
