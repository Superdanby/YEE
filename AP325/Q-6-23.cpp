#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 1e9 + 9;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const int monster_cnt) {
  multiset<int> ms;
  int front, back;
  for (int i = 0; i < monster_cnt; ++i) {
    cin >> front >> back;
    ms.insert(front);
    auto it = ms.upper_bound(back);
    if (it != ms.end()) ms.erase(it);
  }
  return ms.size();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll monster_cnt;
  cin >> monster_cnt;
  cout << solve(monster_cnt) << "\n";

  return 0;
}
