#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

void solve(vector<queue<int>> &graph) {
  vector<pair<int, int>> ans;
  queue<int> que;
  for (int i = 1; i < graph.size(); ++i) que.push(i);
  int limit = graph.size() - 1, cnt = 0;
  while (!que.empty() && cnt < limit) {
    auto node = que.front();
    que.pop();
    if (graph[node].empty()) {
      --limit;
      continue;
    }
    que.push(node);
    ++cnt;
    if (graph[graph[node].front()].front() == node) {
      ans.push_back({node, graph[node].front()});
      graph[graph[node].front()].pop();
      graph[node].pop();
      cnt = 0;
    }
  }
  if (!que.empty()) cout << "-1\n";
  for (const auto &x : ans) cout << x.first << " " << x.second << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<queue<int>> graph(node_cnt + 1);
  int neighbor_cnt, inp;
  for (int i = 1; i <= node_cnt; ++i) {
    cin >> neighbor_cnt;

    for (int j = 0; j < neighbor_cnt; ++j) {
      cin >> inp;
      graph[i].push(inp);
    }
  }
  solve(graph);
  return 0;
}