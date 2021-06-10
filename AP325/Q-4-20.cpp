#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int solve(vector<pair<int, int>> &coverage, const int start, const int stop) {
  sort(coverage.begin(), coverage.end());
  int limit = start, next = start, ans = 0;
  for (const auto &x : coverage) {
    if (x.first > next) return -1;
    if (x.first > limit) {
      ++ans;
      limit = next;
    }
    if (x.second >= limit) {
      next = x.second > next ? x.second : next;
    }
    if (next >= stop) return ans + 1;
  }
  return -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int apprentices;
  cin >> apprentices;
  int start, stop;
  cin >> start >> stop;
  vector<pair<int, int>> coverage(apprentices);
  for (auto &x : coverage) cin >> x.first >> x.second;

  cout << solve(coverage, start, stop) << "\n";

  return 0;
}
