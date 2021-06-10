#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;
// constexpr const ll MAX = 1e18;

void matrix_sqr(vector<vector<ll>> &m, vector<vector<ll>> &n,
                vector<vector<ll>> &o) {
  // for (const auto &x : m) {
  //   for (const auto &y : x) cout << y << " ";
  //   cout << "m\n\n";
  // }
  // for (const auto &x : n) {
  //   for (const auto &y : x) cout << y << " ";
  //   cout << "n\n\n";
  // }
  if (m.front().size() != n.size()) {
    o.clear();
    return;
  }

  o.resize(m.size());
  for (size_t i = 0; i < m.size(); ++i) {
    o[i].resize(n.size());
    for (size_t j = 0; j < n.front().size(); ++j) {
      o[i][j] = 0;
      for (size_t k = 0; k < n.size(); ++k) o[i][j] += m[i][k] * n[k][j] % MOD;
    }
  }

  // for (const auto &x : o) {
  //   for (const auto &y : x) cout << y << " ";
  //   cout << "o\n\n";
  // }
}

ll solve(ll exp_target) {
  ll exp = 1;
  vector<vector<ll>> base{{0, 1}, {1, 1}}, ans{{1, 0}, {0, 1}}, want;
  while (exp_target >= exp) {
    if (exp & exp_target) {
      matrix_sqr(base, ans, want);
      ans.swap(want);
    }
    vector<vector<ll>> duplicate(base);
    matrix_sqr(base, duplicate, want);
    base.swap(want);
    exp <<= 1;
  }
  vector<vector<ll>> start{{0}, {1}};
  matrix_sqr(ans, start, want);
  return want.front().front();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  ll inp;
  while (cin >> inp) {
    if (inp == -1) break;
    cout << solve(inp) << "\n";
  }

  // }
  // for (const auto &x : cut) cout << x << " ";
  // cout << "\n";

  return 0;
}
