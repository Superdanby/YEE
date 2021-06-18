#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

void tarjan(vector<unordered_set<int>> &graph, vector<int> &order,
            vector<int> &scc, const int parent, const int node) {
  static int accumulate = 0;
  order[node] = scc[node] = ++accumulate;
  for (const auto &x : graph[node]) {
    if (!order[x]) {  // new node
      tarjan(graph, order, scc, node, x);
      scc[node] = scc[x] < scc[node] ? scc[x] : scc[node];
    } else if (parent != x)
      scc[node] = order[x] < scc[node] ? order[x] : scc[node];
  }
}

void get_ans(vector<unordered_set<int>> &graph, string &ans, const int node,
             char io) {
  if (node < graph.size() / 2) {
    ans[node] = io;
    ans[node + graph.size() / 2] = io == 'i' ? 'o' : 'i';
  } else {
    ans[node] = io;
    ans[node - graph.size() / 2] = io == 'i' ? 'o' : 'i';
  }
  for (const auto &x : graph[node])
    if (ans[x] == '-') get_ans(graph, ans, x, io);
}

void solve(vector<pair<int, int>> &edges) {
  vector<unordered_set<int>> graph(edges.size() * 2);  // in + out

  // build rules
  for (auto &x : edges)
    if (x.first > x.second) swap(x.first, x.second);
  for (int i = 0; i < edges.size(); ++i) {
    for (int j = i + 1; j < edges.size(); ++j) {
      if (edges[i].second <= edges[j].first ||
          edges[j].second <= edges[i].first ||
          (edges[i].first <= edges[j].first &&
           edges[j].second <= edges[i].second) ||
          (edges[j].first <= edges[i].first &&
           edges[i].second <= edges[j].second))
        continue;
      graph[i].insert(edges.size() + j);
      graph[j].insert(edges.size() + i);
      graph[edges.size() + i].insert(j);
      graph[edges.size() + j].insert(i);
    }
  }
  // for (int i = 0; i < graph.size(); ++i) {
  //   cerr << i << ":";
  //   for (const auto &x : graph[i]) cerr << " " << x;
  //   cerr << "\n";
  // }
  vector<int> order(graph.size()), scc(graph.size());
  for (int i = 0; i < graph.size(); ++i)
    if (!order[i]) tarjan(graph, order, scc, i, i);
  for (int i = 0, j = edges.size(); j < graph.size(); ++i, ++j)
    if (scc[i] == scc[j]) {
      cout << "Impossible\n";
      return;
    }
  string ans(graph.size(), '-');
  for (int i = 0; i < ans.length(); ++i)
    if (ans[i] == '-') get_ans(graph, ans, i, 'i');
  ans.resize(edges.size());
  cout << ans << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int city_cnt, edge_cnt;
  cin >> city_cnt >> edge_cnt;
  vector<pair<int, int>> edges(edge_cnt);
  for (auto &x : edges) cin >> x.first >> x.second;
  solve(edges);
  return 0;
}