#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

bool solve(vector<vector<int>> &graph) {
  vector<short> colors(graph.size());
  queue<int> que;
  for (int i = 0; i < colors.size(); ++i) {
    if (!colors[i]) {
      colors[i] = 1;
      que.push(i);
      while (!que.empty()) {
        auto node = que.front();
        que.pop();
        for (const auto &x : graph[node]) {
          if (!colors[x]) {
            colors[x] = colors[node] ^ (short)3;
            que.push(x);
          } else if (colors[x] == colors[node])
            return false;
        }
      }
    }
  }
  return true;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int cases;
  cin >> cases;
  while (cases--) {
    int vertex_cnt, edge_cnt;
    cin >> vertex_cnt >> edge_cnt;
    vector<vector<int>> graph(vertex_cnt);
    int from, to;
    for (int i = 0; i < edge_cnt; ++i) {
      cin >> from >> to;
      graph[from].push_back(to);
      graph[to].push_back(from);
    }
    if (solve(graph))
      cout << "yes\n";
    else
      cout << "no\n";
  }

  return 0;
}
