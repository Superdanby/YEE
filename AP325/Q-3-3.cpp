#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

int solve(const vector<vector<int>> &tree, const int parent, ll &accumulate) {
  int depth = 0;
  for (const auto x : tree[parent]) {
    int ret = solve(tree, x, accumulate);
    depth = depth < ret ? ret : depth;
  }
  if (!tree[parent].empty()) ++depth;
  accumulate += depth;
  return depth;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  char inp;
  stack<char> oper;
  stack<ll> num;
  while (cin >> inp) {
    if (inp - '0' >= 0 && inp - '0' <= 9) {
      num.push(inp - '0');
    } else if (inp == '*' || inp == '/') {
      ll front = num.top();
      num.pop();
      if (inp == '*') {
        cin >> inp;
        num.push(front * (inp - '0'));
      } else {
        cin >> inp;
        num.push(front / (inp - '0'));
      }
    } else {
      oper.push(inp);
    }
    // cerr << num.top() << "\n";
  }
  ll ans = 0;
  while (!oper.empty()) {
    // cerr << oper.top() << num.top() << "\n";
    if (oper.top() == '+')
      ans += num.top();
    else
      ans -= num.top();

    num.pop();
    oper.pop();
  }
  cout << (num.empty() ? 0 : num.top()) + ans << "\n";
  return 0;
}
