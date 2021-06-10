#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll solve(const int target) {
  vector<ll> C(target + 1);
  C.front() = 1;
  for (int i = 1; i < C.size(); ++i)
    for (int j = 0; j < i; ++j)
      C[i] = (C[i] + (C[j] * C[i - 1 - j]) % MOD) % MOD;

  return C.back();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int target;
  cin >> target;

  cout << solve(target) << "\n";

  return 0;
}
