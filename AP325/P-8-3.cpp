#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void traverse(vector<unordered_map<int, int>> &tree, vector<ll> &costs,
              vector<int> &child_cnt, const int node) {
  for (const auto &x : tree[node]) {
    if (costs[x.first] == -1) {
      costs[x.first] = 0;
      traverse(tree, costs, child_cnt, x.first);
      costs[node] += costs[x.first];
      child_cnt[node] += child_cnt[x.first];
      costs[node] += child_cnt[x.first] * x.second;
    }
  }
  ++child_cnt[node];
  // for (const auto &x : costs) cerr << x << " ";
  // cerr << "\n";
}

int mid(vector<unordered_map<int, int>> &tree, vector<bool> &visited, int node,
        int &ans) {
  int node_cnt = 1;
  for (const auto &x : tree[node]) {
    if (!visited[x.first]) {
      visited[x.first] = true;
      node_cnt += mid(tree, visited, x.first, ans);
      if (ans) return -1;
    }
  }
  if (node_cnt >= tree.size() / 2) ans = node;

  // cerr << node << ": " << node_cnt << "\n";

  return node_cnt;
}

void solve(vector<unordered_map<int, int>> &tree) {
  int mid_node = 0;
  vector<bool> visited(tree.size());
  mid(tree, visited, 0, mid_node);
  vector<ll> costs(tree.size(), -1);
  costs[mid_node] = 0;
  vector<int> child_cnt(tree.size());
  traverse(tree, costs, child_cnt, mid_node);
  cout << mid_node << "\n";
  cout << costs[mid_node] << "\n";

  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt;
  cin >> vertex_cnt;
  vector<unordered_map<int, int>> tree(vertex_cnt);
  for (int to = 1; to < vertex_cnt; ++to) {
    int from, cost;
    cin >> from >> cost;
    tree[from].insert({to, cost});
    tree[to].insert({from, cost});
  }
  solve(tree);

  return 0;
}
