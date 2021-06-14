#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1LL << 32;
constexpr const ll MOD = 1e9 + 9;

ll solve(const string &A, const string &B) {
  // kmp
  vector<int> teleport(B.length());
  for (int i = 1, j = 0; i < B.length(); ++i) {
    while (B[i] != B[j] && j != 0) {
      j = teleport[j - 1];
    }
    if (B[i] != B[j]) continue;
    teleport[i] = ++j;
  }
  ll cnt = 0;
  for (int i = 0, j = 0; i < A.length(); ++i) {
    while (j != 0 && A[i] != B[j]) j = teleport[j - 1];
    if (A[i] == B[j]) {
      if (j == teleport.size() - 1)
        ++cnt, j = 0;
      else
        ++j;
    }
  }
  return cnt;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string A, B;
  cin >> A >> B;
  cout << solve(A, B) << "\n";

  return 0;
}