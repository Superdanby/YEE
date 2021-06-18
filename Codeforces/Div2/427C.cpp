#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

void tarjan(vector<unordered_set<int>> &graph, vector<int> &order,
            vector<int> &ancestor, stack<int> &subtree,
            vector<bool> &in_subtree, vector<int> &scc, const int node) {
  static int accumulate = 0;
  order[node] = ancestor[node] = ++accumulate;
  in_subtree[node] = true;
  subtree.push(node);
  for (const auto &x : graph[node]) {
    if (!order[x]) {  // new node
      tarjan(graph, order, ancestor, subtree, in_subtree, scc, x);
      ancestor[node] =
          ancestor[x] < ancestor[node] ? ancestor[x] : ancestor[node];
    } else if (in_subtree[x]) {  // not cross edge
      ancestor[node] = order[x] < ancestor[node] ? order[x] : ancestor[node];
    }
  }
  if (order[node] == ancestor[node]) {  // first point of SCC
    while (!subtree.empty() && order[subtree.top()] >= order[node]) {
      scc[subtree.top()] = order[node];
      in_subtree[subtree.top()] = false;
      subtree.pop();
    }
  }
}

void solve(vector<unordered_set<int>> &graph, vector<int> &costs) {
  // for (int i = 0; i < graph.size(); ++i) {
  //   cerr << i << ":";
  //     for (const auto &x: graph[i]) {
  //       cerr << " " << x ;
  //     }
  //     cerr << "\n";
  // }
  vector<int> order(graph.size()), ancestor(graph.size()), scc(graph.size());
  stack<int> subtree;
  vector<bool> in_subtree(graph.size());
  for (int i = 0; i < graph.size(); ++i)
    if (!order[i]) tarjan(graph, order, ancestor, subtree, in_subtree, scc, i);
  unordered_map<int, pair<int, int>> SCC;
  // for (const auto &x: order ) cerr << x << " ";
  // cerr << "\n";
  // for (const auto &x: scc ) cerr << x << " ";
  // cerr << "\n";
  for (int i = 0; i < scc.size(); ++i) {
    const auto [_, success] = SCC.insert({scc[i], {costs[i], 1}});
    if (!success) {
      if (costs[i] < SCC[scc[i]].first)
        SCC[scc[i]] = {costs[i], 1};
      else if (costs[i] == SCC[scc[i]].first)
        ++SCC[scc[i]].second;
    }
  }

  ll total = 0, combinations = 1;
  for (const auto &[_, x] : SCC) {
    total += x.first;
    combinations = (combinations * x.second) % MOD;
  }

  cout << total << " " << combinations << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int city_cnt;
  cin >> city_cnt;
  vector<int> costs(city_cnt);
  for (auto &x : costs) cin >> x;
  int edge_cnt;
  cin >> edge_cnt;
  vector<unordered_set<int>> graph(city_cnt);
  int from, to;
  while (edge_cnt--) {
    cin >> from >> to;
    graph[from - 1].insert(to - 1);
  }
  solve(graph, costs);
  return 0;
}