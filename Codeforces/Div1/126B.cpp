#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

string solve(const string &inp) {
  // kmp does not work, ending suffix may or may not be a prefix in the middle
  // of the string

  // vector<int> shift(inp.length()); for (int i = 1, j = 0; i <
  // inp.length(); ++i) {
  //   while (j != 0 && inp[i] != inp[j]) j = shift[j - 1];
  //   if (inp[i] == inp[j]) ++j;
  //   shift[i] = j;
  // }

  // z-algorithm
  string zstr = inp;
  vector<int> z(zstr.length());
  // z box is the right-most bounding box that constains the longest prefix
  // z box may not contain the longest prefix, but it should always be the
  // right-most bounding box z box's left edge, l, should always be lesser or
  // equal to current index, i
  int limit = 0;  // the largest length of prefixes which are not suffixes
  for (int i = 1, l = 0, r = 0; i < z.size(); ++i) {
    // z[i - l] should not exceed the right bound of the current z box
    // and if r -i + 1 < 0, i is outside the current z box
    auto prefix_candidate = z[i - l] < r - i + 1 ? z[i - l] : r - i + 1;
    z[i] = 0 > prefix_candidate ? 0 : prefix_candidate;

    // if possible, reset and extend the z-box
    while (z[i] + i < zstr.length() && zstr[z[i]] == zstr[z[i] + i])
      l = i, r = z[i] + i, ++z[i];
    if (z[i] + i == zstr.length()) {
      limit = z[i] - 1 > limit ? z[i] - 1 : limit;
    } else
      limit = z[i] > limit ? z[i] : limit;
  }

  int ans = 0;
  for (int i = 0; i < zstr.size(); ++i) {
    if (z[i] + i == zstr.length() && z[i] <= limit)
      ans = z[i] > ans ? z[i] : ans;
  }

  if (ans > 0) return inp.substr(0, ans);

  return "Just a legend";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string inp;
  cin >> inp;
  cout << solve(inp) << "\n";

  return 0;
}