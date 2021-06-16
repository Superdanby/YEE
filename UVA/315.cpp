#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void tarjan(vector<unordered_set<int>> &graph, vector<int> &order,
            vector<int> &scc, ll &ans, const int parent, const int node) {
  static int accumulate = 0;
  order[node] = scc[node] = ++accumulate;
  int sub_tree_cnt = 0;               // root check point
  bool sub_tree_no_ancestor = false;  // non-root check point
  for (const auto &x : graph[node]) {
    if (!order[x]) {  // new node
      ++sub_tree_cnt;
      tarjan(graph, order, scc, ans, node, x);
      scc[node] = scc[x] < scc[node] ? scc[x] : scc[node];
      if (scc[x] >= order[node])  // sub-tree not connected with an ancestor
        sub_tree_no_ancestor = true;
    } else if (x != parent)  // is ancestor but not parent
      scc[node] = order[x] < scc[node] ? order[x] : scc[node];
  }

  // root has 2 or more sub-trees || non root node having a sub-tree not
  // connected with an ancestor
  if ((node == parent && sub_tree_cnt > 1) ||
      (node != parent && sub_tree_no_ancestor)) {
    ++ans;
  }
}

ll solve(vector<unordered_set<int>> &graph) {
  vector<int> order(graph.size()), scc(graph.size());
  ll ans = 0;
  for (int i = 0; i < graph.size(); ++i) {
    if (order[i]) continue;
    tarjan(graph, order, scc, ans, i, i);
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int city_cnt;
  string inp_raw;
  while (cin >> city_cnt) {
    if (!city_cnt) break;
    vector<unordered_set<int>> graph(city_cnt);
    int from;
    while (getline(cin, inp_raw)) {
      if (inp_raw.empty()) continue;
      istringstream iss(inp_raw);
      iss >> from;
      if (!from) break;
      int to;
      while (iss >> to) {
        graph[from - 1].insert(to - 1);
        graph[to - 1].insert(from - 1);
      }
    }
    cout << solve(graph) << "\n";
  }
  return 0;
}