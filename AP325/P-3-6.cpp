#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

pair<int, int> solve(vector<int> &position, vector<int> &height, int right) {
  stack<int> st;
  int cnt = 0, MAX = 0;
  for (int i = 0; i < position.size(); ++i) {
    if (position[i] - height[i] >= (st.empty() ? 0 : position[st.top()]) ||
        position[i] + height[i] <=
            (i + 1 == position.size() ? right : position[i + 1])) {
      ++cnt;
      MAX = MAX < height[i] ? height[i] : MAX;
      while (!st.empty() &&
             position[st.top()] + height[st.top()] <=
                 (i + 1 == position.size() ? right : position[i + 1])) {
        ++cnt;
        MAX = MAX < height[st.top()] ? height[st.top()] : MAX;
        st.pop();
      }
    } else
      st.push(i);
  }
  return pair<int, int>(cnt, MAX);
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int trees, right;
  cin >> trees >> right;
  vector<int> position(trees), height(trees);

  for (auto &x : position) cin >> x;
  for (auto &x : height) cin >> x;

  auto ans = solve(position, height, right);
  cout << ans.first << "\n" << ans.second << "\n";
  return 0;
}
