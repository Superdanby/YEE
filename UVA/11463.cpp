#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
constexpr const int INF = 0x3f3f3f3f;

ll solve(vector<vector<int>> graph, const int start, const int tail) {
  for (int i = 0; i < graph.size(); ++i) graph[i][i] = 0;
  for (int k = 0; k < graph.size(); ++k) {
    for (int i = 0; i < graph.size(); ++i) {
      for (int j = i + 1; j < graph.size(); ++j) {
        graph[j][i] = graph[i][j] = graph[i][k] + graph[k][j] < graph[i][j]
                                        ? graph[i][k] + graph[k][j]
                                        : graph[i][j];
      }
    }
  }
  int ans = -INF;
  for (int i = 0; i < graph.size(); ++i)
    ans = graph[start][i] + graph[i][tail] > ans
              ? graph[start][i] + graph[i][tail]
              : ans;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin >> cases;
  for (int i = 1; i <= cases; ++i) {
    int node_cnt, edge_cnt;
    cin >> node_cnt >> edge_cnt;
    vector<vector<int>> graph(node_cnt,
                              vector<int>(node_cnt, INF));  // to, cost
    for (int i = 0, from, to; i < edge_cnt; ++i) {
      cin >> from >> to;
      graph[from][to] = 1;
      graph[to][from] = 1;
    }
    int start, tail;
    cin >> start >> tail;
    cout << "Case " << i << ": " << solve(graph, start, tail) << "\n";
  }

  return 0;
}