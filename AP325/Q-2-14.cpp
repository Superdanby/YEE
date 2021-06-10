#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

void solve(const vector<ll> &height, const ll start, const ll quantity,
           vector<ll> &ans, const vector<ll> &lhigher,
           const vector<ll> &rhigher, ll roof) {
  if (start < 0 || start >= height.size() - 1 || quantity == 0) return;

  auto left = start, right = start + 1;
  ll ub = roof, lb = 0;

  // cerr << start << "\n";
  while (ub - lb > 1) {
    ll pivot = (ub + lb) / 2;
    while (height[left] < pivot) left = lhigher[left];
    while (height[right] < pivot) right = rhigher[right];
    // for (auto &x : prefix) cout << x << " ";
    // cout << pivot << "p\n";
    // cout << left - prefix.begin() << "\n";
    if ((right - left) * pivot > quantity)
      ub = pivot;
    else
      lb = pivot;
    left = start, right = start + 1;
  }
  // cout << lb << "lb\n";
  while (height[left] < lb) left = lhigher[left];
  while (height[right] < lb) right = rhigher[right];
  // cerr << left << "-" << lb << "-" << right << "\n";
  for (int i = left; i < right; ++i) ans[i] = lb;
  if (height[left] > height[right])
    solve(height, right, quantity - lb * (right - left), ans, lhigher, rhigher,
          lb + 1);
  else
    solve(height, left - 1, quantity - lb * (right - left), ans, lhigher,
          rhigher, lb + 1);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll nums, start, quantity;
  cin >> nums >> start >> quantity;
  vector<ll> height(nums), ans(nums - 1);
  for (auto &x : height) cin >> x;

  vector<ll> lhigher(nums), rhigher(nums);
  lhigher.front() = 0;
  lhigher.back() = lhigher.size() - 1;
  for (int i = 1; i < lhigher.size() - 1; ++i) {
    int j = i - 1;
    while (height[j] < height[i]) j = lhigher[j];
    lhigher[i] = j;
  }
  rhigher.front() = 0;
  rhigher.back() = rhigher.size() - 1;
  for (int i = rhigher.size() - 2; i > 0; --i) {
    int j = i + 1;
    while (height[j] < height[i]) j = rhigher[j];
    rhigher[i] = j;
  }
  solve(height, start, quantity, ans, lhigher, rhigher,
        height.front() < height.back() ? height.back() : height.front());

  auto it = ans.begin();
  cout << *it;
  for (++it; it != ans.end(); ++it) cout << " " << *it;
  cout << "\n";

  return 0;
}
