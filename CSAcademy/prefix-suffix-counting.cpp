// https://csacademy.com/contest/archive/task/prefix-suffix-counting/statement
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

// A >= B
bool ge(string::const_iterator a_it, string::const_iterator a_end,
        string::const_iterator b_it, string::const_iterator b_end) {
  if (a_end - a_it < b_end - b_it) return false;
  if (a_end - a_it > b_end - b_it) return true;
  for (; a_it != a_end; ++a_it, ++b_it) {
    if (*(a_it) < *(b_it)) return false;
    if (*(a_it) > *(b_it)) return true;
  }
  return true;
}

// Construct all targets where targets <= A
ll solve(const string &A, const string &B) {
  // A < B
  if (!ge(A.begin(), A.end(), B.begin(), B.end())) return 0;

  ll ans = 0;

  // kmp
  vector<int> shift(B.length());
  for (int i = 1, j = 0; i < shift.size(); ++i) {
    while (j != 0 && B[i] != B[j]) j = shift[j - 1];
    if (B[i] == B[j]) ++j;
    shift[i] = j;
  }

  // Self overlapping index while length not exceeding length of A and smaller
  // than 2 * length of B: E.g. ababa overlaps at [ababa], ab[aba]ba,
  // abab[a]baba
  for (int i = B.length() - 1; i != -1 && 2 * B.length() - i - 1 <= A.length();
       i = shift[i] - 1)
    ++ans;
  if (A.length() < 2 * B.length()) return ans;

  // Length >= 2 * length of B
  ll add = 1;
  int length = 2 * B.length();
  while (length < A.length()) {
    ans = (ans + add) % MOD;
    ++length;
    add = add * 10 % MOD;
  }

  if (!ge(A.begin(), A.begin() + B.length(), B.begin(), B.end()))
    return ans;  // prefix of A < B, target of length A > A

  if (!ge(B.begin(), B.end(), A.begin(), A.begin() + B.length()))
    return (ans + add) % MOD;  // B < prefix of A, target of length A < A

  // Prefix of A == B
  // E.g. A = 123?, B = 1, valid target count = 23
  add = 0;
  for (int i = B.length(); i < A.length() - B.length(); ++i) {
    add = (add * 10 + A[i] - '0') % MOD;
  }
  ans += add;

  // Suffix of A >= B, target of length A <= A
  // E.g. A = 121, B = 1, valid targets = 121, 111, 101
  // E.g. A = 120, B = 1, valid targets = 111, 101
  if (ge(A.end() - B.length(), A.end(), B.begin(), B.end())) ++ans;

  return ans % MOD;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string A, B;
  cin >> A >> B;
  cout << solve(A, B) << "\n";

  return 0;
}