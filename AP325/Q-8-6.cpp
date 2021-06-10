#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll node_1(vector<vector<pair<int, ll>>> &tree, vector<ll> &status,
          const int node) {
  status[node] = 1;
  ll ans = 0;
  for (const auto x : tree[node]) {
    // cerr << x.first << " node";
    if (!status[x.first]) {
      ans += node_1(tree, status, x.first);
      status[node] += status[x.first];
      ans +=
          status[x.first] * x.second * (tree.size() - 1 - status[x.first]) * 2;
      // cerr << status[x.first] << " " << x.second << " "
      //      << (tree.size() - 1 - status[x.first]) << "\n";
    }
  }
  // for (const auto &x : status) cerr << x << " ";
  // cerr << "\n";
  return ans;
}

ll solve(vector<vector<pair<int, ll>>> &tree) {
  vector<ll> status(tree.size());  // node_cnt
  return node_1(tree, status, 1);
  // for (const auto &x : status) cerr << x.first << " ";
  // cerr << "\n";
  // for (const auto &x : status) cerr << x.second << " ";
  // cerr << "\n";
  // for (int i = 2; i < status.size(); ++i) status[i].second = 0;
  // node_all(tree, status, 1);
  // for (const auto &x : status) cerr << x.first << " ";
  // cerr << "\n";
  // for (const auto &x : status) cerr << x.second << " ";
  // cerr << "\n";
  // ll ans = 0;
  // for (const auto &x : status) {
  //   ans += x.second;
  // }
  // return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  vector<vector<pair<int, ll>>> graph(node_cnt + 1);
  vector<pair<int, ll>> edges(node_cnt - 1);
  for (auto &x : edges) cin >> x.first;
  for (auto &x : edges) cin >> x.second;
  for (int i = 0; i < edges.size(); ++i) {
    graph[edges[i].first].push_back({i + 2, edges[i].second});
    graph[i + 2].push_back({edges[i].first, edges[i].second});
  }
  cout << solve(graph) << "\n";

  return 0;
}
