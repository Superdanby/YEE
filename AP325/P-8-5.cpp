#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

void build(vector<pair<int, int>> &tree, vector<ll> &weight, const int node) {
  if (tree[node].first) build(tree, weight, tree[node].first);
  if (tree[node].second) build(tree, weight, tree[node].second);
  weight[node] += weight[tree[node].first] + weight[tree[node].second];
}

int update(vector<pair<int, int>> &tree, vector<ll> &weight, const int node,
           const int add) {
  weight[node] += add;
  if (!tree[node].first && !tree[node].second) return node;
  if (!tree[node].second) return update(tree, weight, tree[node].first, add);
  if (!tree[node].first) return update(tree, weight, tree[node].second, add);
  if (weight[tree[node].first] <= weight[tree[node].second])
    return update(tree, weight, tree[node].first, add);
  return update(tree, weight, tree[node].second, add);
}

void solve(vector<pair<int, int>> &tree, vector<ll> &weight,
           vector<ll> &packages) {
  build(tree, weight, 1);
  vector<int> ans;
  // for (const auto &x : weight) cerr << x << " ";
  // cerr << "\n";
  for (const auto &x : packages) ans.push_back(update(tree, weight, 1, x));
  auto it = ans.begin();
  cout << *it;
  for (++it; it != ans.end(); ++it) cout << " " << *it;
  cout << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int leaf_cnt, package_cnt;
  cin >> leaf_cnt >> package_cnt;
  vector<ll> weight(leaf_cnt * 2);  // 1-based
  for (int i = leaf_cnt; i < weight.size(); ++i) cin >> weight[i];
  vector<ll> packages(package_cnt);
  for (auto &x : packages) cin >> x;
  vector<pair<int, int>> tree(weight.size());
  int from, left, right;
  for (int i = 1; i < leaf_cnt; ++i) {
    cin >> from >> left >> right;
    tree[from] = {left, right};
  }
  solve(tree, weight, packages);

  return 0;
}
