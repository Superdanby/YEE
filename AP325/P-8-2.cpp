#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void solve(vector<unordered_map<int, int>> &tree) {
  ll max_cost = 0, max_nodes = 0, cost = 0, nodes = 0;
  stack<pair<int, int>> st;  // node, cost to substract
  vector<int> sequence{0};
  st.push({0, 0});
  while (!st.empty()) {
    auto x = st.top();
    if (tree[x.first].empty()) {
      st.pop();
      max_cost = cost > max_cost ? cost : max_cost;
      max_nodes = nodes > max_nodes ? nodes : max_nodes;
      cost -= x.second;
      --nodes;
      continue;
    }
    auto it = tree[x.first].begin();
    cost += it->second;
    ++nodes;
    st.push({it->first, it->second});
    tree[x.first].erase(it);
  }
  cout << max_cost << "\n";
  cout << max_nodes << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt;
  cin >> vertex_cnt;
  vector<unordered_map<int, int>> tree(vertex_cnt);
  for (int to = 1; to < vertex_cnt; ++to) {
    int from, cost;
    cin >> from >> cost;
    tree[from].insert({to, cost});
  }
  solve(tree);

  return 0;
}
