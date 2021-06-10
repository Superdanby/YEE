#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

// constexpr vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
const vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ll solve(const vector<vector<char>> &graph) {
  if (graph.size() <= 1 && graph.front().size() <= 1) return 0;
  vector<vector<int>> turns(vector<vector<int>>(
      graph.size() + 2,
      vector<int>(graph.front().size() + 2, -1)));  // padded -INF
  for (int i = 0; i < graph.size(); ++i)
    for (int j = 0; j < graph[i].size(); ++j)
      turns[i + 1][j + 1] = graph[i][j] == '0' ? INF : -1;

  turns[1][1] = -1;

  queue<pair<int, int>> que;  // coordinates
  turns[0 + 1][0 + 1] = -1;
  que.push({0, 0});

  while (!que.empty()) {
    for (int i = 0; i < direction.size(); ++i) {
      auto x = que.front();
      while (turns[x.first + direction[i].first + 1]
                  [x.second + direction[i].second + 1] == INF) {
        x.first += direction[i].first, x.second += direction[i].second;
        turns[x.first + 1][x.second + 1] =
            turns[que.front().first + 1][que.front().second + 1] + 1;
        que.push({x.first, x.second});
      }
    }
    que.pop();
  }
  // for (const auto &x : turns) {
  //   for (const auto &y : x) cerr << setw(15) << y << " ";
  //   cerr << "\n";
  // }

  return turns[graph.size()][graph.back().size()] != INF
             ? turns[graph.size()][graph.back().size()]
             : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int rows, cols;
  cin >> rows >> cols;
  vector<vector<char>> graph(rows, vector<char>(cols));
  for (auto &x : graph)
    for (auto &y : x) cin >> y;
  cout << solve(graph) << "\n";

  return 0;
}
