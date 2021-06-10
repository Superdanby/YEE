#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void solve(vector<map<int, int>> &tree) {
  ll cost = 0;
  stack<int> st;
  vector<int> sequence{0};
  unordered_map<int, int> parent;
  parent[0] = -1;
  st.push(0);
  while (!st.empty()) {
    auto x = st.top();
    if (tree[x].empty()) {
      st.pop();
      sequence.push_back(parent[x]);
      continue;
    }
    auto it = tree[x].begin();
    cost += it->second * 2;
    auto next = it->first;
    sequence.push_back(next);
    st.push(next);
    parent[next] = x;
    tree[x].erase(it);
    tree[next].erase(x);
  }
  sequence.pop_back();
  cout << cost << "\n";
  auto it = sequence.begin();
  cout << *it;
  for (++it; it != sequence.end(); ++it) cout << " " << *it;
  cout << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt;
  cin >> vertex_cnt;
  vector<map<int, int>> tree(vertex_cnt);
  for (int i = 0; i < vertex_cnt - 1; ++i) {
    int from, to, cost;
    cin >> from >> to >> cost;
    tree[from][to] = cost;
    tree[to][from] = cost;
  }
  solve(tree);

  return 0;
}
