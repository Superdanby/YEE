#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void tarjan(vector<unordered_set<int>> &graph, vector<int> &order,
            vector<int> &scc, set<pair<int, int>> &ans, const int parent,
            const int node) {
  static int accumulate = 0;
  order[node] = scc[node] = ++accumulate;
  for (const auto &x : graph[node]) {
    if (!order[x]) {  // new node
      tarjan(graph, order, scc, ans, node, x);
      scc[node] = scc[x] < scc[node] ? scc[x] : scc[node];
      if (scc[x] > order[node]) {  // subtree not in node SCC or ancestor SCC
        node < x ? ans.insert({node, x}) : ans.insert({x, node});
      }
    } else if (x != parent)  // ancestor
      scc[node] = order[x] < scc[node] ? order[x] : scc[node];
  }
}

void solve(vector<unordered_set<int>> &graph) {
  // for (int i = 0; i < graph.size(); ++i) {
  //   cerr << i << ":";
  //   for (const auto &x: graph[i])
  //     cerr << " " << x;
  //   cerr << "\n";
  // }
  vector<int> order(graph.size()), scc(graph.size());
  set<pair<int, int>> ans;
  for (int i = 0; i < graph.size(); ++i) {
    if (order[i]) continue;
    tarjan(graph, order, scc, ans, i, i);
  }
  // for (const auto &x: order) cerr << x << " ";
  // cerr << "\n";
  // for (const auto &x: scc) cerr << x << " ";
  // cerr << "\n";
  cout << ans.size() << " critical links\n";
  for (const auto &x : ans) cout << x.first << " - " << x.second << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  char ignore;
  while (cin >> node_cnt) {
    vector<unordered_set<int>> graph(node_cnt);
    for (int i = 0, from, to_cnt, to; i < node_cnt; ++i) {
      cin >> from >> ignore >> to_cnt >> ignore;
      for (int j = 0; j < to_cnt; ++j) {
        cin >> to;
        graph[from].insert(to);
        graph[to].insert(from);
      }
    }
    solve(graph);
    cout << "\n";
  }
  return 0;
}