#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

int root(vector<int> &union_set, const int x) {
  if (union_set[x] == x) return x;
  return union_set[x] = root(union_set, union_set[x]);
}

bool merge(vector<int> &union_set, int x, int y) {
  if ((x = root(union_set, x)) == (y = root(union_set, y))) return false;
  union_set[x] = y;
  return true;
}

ll solve(vector<pair<int, pair<int, int>>> &edges, vector<int> &union_set) {
  sort(edges.begin(), edges.end());
  ll ans = 0, ans_cnt = union_set.size() - 1;
  for (const auto &x : edges) {
    // cerr << x.second.first << " " << x.second.second << "\n";
    // for (const auto &y : union_set) cerr << y << " ";
    // cerr << "\n";
    if (!merge(union_set, x.second.first, x.second.second)) continue;
    ans += x.first;
    --ans_cnt;
  }
  // cerr << ans << " " << ans_cnt << "\n";
  if (ans_cnt) return -1;
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt, edge_cnt;
  cin >> vertex_cnt >> edge_cnt;
  vector<int> union_set(vertex_cnt);
  for (int i = 0; i < union_set.size(); ++i) union_set[i] = i;
  vector<pair<int, pair<int, int>>> edges(edge_cnt);
  for (auto &x : edges) {
    cin >> x.second.first >> x.second.second >> x.first;
  }
  cout << solve(edges, union_set) << "\n";

  return 0;
}
