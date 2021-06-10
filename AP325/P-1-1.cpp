#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
// constexpr const int MAX = 2147483647;
constexpr const int MAX = 0x3f3f3f3f;

string solve(list<string>& formula) {
  auto it = formula.end();
  while (true) {
    --it;
    if (it->front() == 'f' || it->front() == 'g') break;
  }
  while (it != formula.begin()) {
    if (it->front() == 'f') {
      auto next = it;
      ++next;
      *it = to_string(2 * stoi(*next) - 1);
      formula.erase(next);
    } else if (it->front() == 'g') {
      auto next = it;
      ++next;
      auto next_next = next;
      ++next_next;
      *it = to_string(stoi(*next) + 2 * stoi(*next_next) - 3);
      formula.erase(next_next);
      formula.erase(next);
    }
    --it;
  }
  if (it->front() == 'f') {
    auto next = it;
    ++next;
    *it = to_string(2 * stoi(*next) - 1);
    formula.erase(next);
  } else if (it->front() == 'g') {
    auto next = it;
    ++next;
    auto next_next = next;
    ++next_next;
    *it = to_string(stoi(*next) + 2 * stoi(*next_next) - 3);
    formula.erase(next_next);
    formula.erase(next);
  }
  return formula.front();
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  // int cases;
  // cin >> cases;
  // while (cases--) {
  string inp;
  list<string> formula;
  while (cin >> inp) {
    formula.push_back(inp);
  }
  cout << solve(formula) << "\n";

  return 0;
}