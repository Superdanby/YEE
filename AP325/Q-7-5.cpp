#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const int INF = 0x3f3f3f3f;
// constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

// constexpr vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

ll solve(const vector<int> &graph, const int goal, const int left,
         const int right) {
  vector<int> steps(graph.size(), INF);
  steps.front() = 0;
  queue<int> que;
  que.push(0);
  while (!que.empty()) {
    auto x = que.front();
    que.pop();
    if (x == goal) continue;
    if (x - left >= 0 && steps[x] + 1 < steps[x - left]) {
      if (graph[x - left] >= 0 && graph[x - left] < graph.size() &&
          steps[x] + 1 < steps[graph[x - left]]) {
        steps[graph[x - left]] = steps[x] + 1;
        que.push(graph[x - left]);
      }
      steps[x - left] = steps[x] + 1;
    }
    if (x + right < graph.size() && steps[x] + 1 < steps[x + right]) {
      if (graph[x + right] >= 0 && graph[x + right] < graph.size() &&
          steps[x] + 1 < steps[graph[x + right]]) {
        steps[graph[x + right]] = steps[x] + 1;
        que.push(graph[x + right]);
      }
      steps[x + right] = steps[x] + 1;
    }
    // for (const auto &x : steps) cerr << x << " ";
    // cerr << "\n";
  }
  return steps[goal] != INF ? steps[goal] : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int num_cnt, goal, left, right;
  cin >> num_cnt >> goal >> left >> right;
  vector<int> graph(num_cnt);
  for (auto &x : graph) cin >> x;
  cout << solve(graph, goal, left, right) << "\n";

  return 0;
}
