#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void traverse(const vector<vector<int>> &graph, const vector<int> &gems,
              unordered_map<int, ll> &sum, ll &ans, const int node) {
  ++sum[gems[node]];
  ans = sum[gems[node]] > ans ? sum[gems[node]] : ans;
  for (const auto &x : graph[node]) traverse(graph, gems, sum, ans, x);
  --sum[gems[node]];
}

ll solve(vector<vector<int>> &graph, vector<int> &gems) {
  // for (int i = 0; i < graph.size(); ++i) {
  //   cerr << i << ": ";
  //   for (const auto &y : graph[i]) cerr << y << " ";
  //   cerr << "\n";
  // }
  unordered_map<int, ll> sum;
  for (const auto &x : gems) sum[x] = 0;
  ll ans = 0;
  traverse(graph, gems, sum, ans, 0);

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<int> gems(node_cnt);
  for (auto &x : gems) cin >> x;

  vector<vector<int>> graph(node_cnt);
  int from, to;
  for (int i = 1; i < node_cnt; ++i) {
    cin >> from >> to;
    graph[from].push_back(to);
  }
  cout << solve(graph, gems) << "\n";

  return 0;
}
