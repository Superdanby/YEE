#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 9;

int solve(const vector<vector<int>> &tree, const int parent, ll &accumulate) {
  int depth = 0;
  for (const auto x : tree[parent]) {
    int ret = solve(tree, x, accumulate);
    depth = depth < ret ? ret : depth;
  }
  if (!tree[parent].empty()) ++depth;
  accumulate += depth;
  return depth;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int lines;
  cin >> lines;
  vector<vector<int>> tree(lines + 1);
  vector<bool> find_root(lines + 1, true);

  for (int i = 1; i < tree.size(); ++i) {
    int children;
    cin >> children;
    int child;
    while (children--) {
      cin >> child;
      tree[i].push_back(child);
      find_root[child] = false;
    }
  }
  int root = 0;
  for (int i = 1; i < find_root.size(); ++i)
    if (find_root[i] == true) {
      root = i;
      break;
    }
  ll accumulate = 0;
  solve(tree, root, accumulate);
  cout << root << "\n" << accumulate << "\n";
  return 0;
}
