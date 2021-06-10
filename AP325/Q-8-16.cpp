#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 32;
constexpr const ll MOD = 1e9 + 9;

constexpr const short all = 4;
constexpr inline short to_short(const char inp) {
  if (inp == 'A') return 0;
  if (inp == 'U') return 1;
  if (inp == 'C') return 2;
  if (inp == 'G') return 3;
  return all;
}

void traverse(vector<vector<int>> &graph, vector<vector<short>> &genes,
              const int &index, vector<vector<ll>> &dp, const int start) {
  if (genes[start][index] == all)
    for (int i = 0; i < all; ++i) dp[i][start] = 0;
  else
    dp[genes[start][index]][start] = 0;
  for (const auto &x : graph[start]) {
    traverse(graph, genes, index, dp, x);
    if (genes[start][index] != all) {
      ll add = INF;
      for (int i = 0; i < all; ++i)
        add = dp[i][x] + (genes[start][index] == i ? 0 : 1) < add
                  ? dp[i][x] + (genes[start][index] == i ? 0 : 1)
                  : add;
      dp[genes[start][index]][start] += add;
    } else {
      for (int i = 0; i < all; ++i) {
        ll add = INF;
        for (int j = 0; j < all; ++j)
          add = dp[j][x] + (i == j ? 0 : 1) < add ? dp[j][x] + (i == j ? 0 : 1)
                                                  : add;
        dp[i][start] += add;
      }
    }
  }
  // for (const auto &x : dp) {
  //   for (const auto &y : x) cerr << setw(15) << y << " ";
  //   cerr << "\n";
  // }
  // cerr << "\n";
}

ll solve(vector<vector<int>> &graph, vector<vector<short>> &genes,
         const int start) {
  ll ans = 0;
  vector<vector<ll>> dp(all, vector<ll>(graph.size()));
  // cerr << genes.front().size() << "r\n";
  for (int i = 0; i < genes.front().size(); ++i) {
    for (auto &x : dp) fill(x.begin(), x.end(), INF);
    traverse(graph, genes, i, dp, start);
    ll local_min = INF;
    for (int j = 0; j < all; ++j)
      local_min = dp[j][start] < local_min ? dp[j][start] : local_min;
    ans += local_min;
    // cerr << "--\n";
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int node_cnt;
  cin >> node_cnt;
  int length;
  cin >> length;
  vector<vector<short>> genes(node_cnt + 1, vector<short>(length));
  vector<vector<int>> graph(node_cnt + 1);  // node, value
  int from, to, start;
  string inp;
  for (int i = 1; i <= node_cnt; ++i) {
    cin >> to >> from >> inp;
    // cerr << inp << "\n";
    for (int j = 0; j < inp.size(); ++j) genes[to][j] = to_short(inp[j]);
    if (from == to) {
      start = from;
      continue;
    }
    graph[from].push_back(to);
  }
  // for (const auto &x : genes) {
  //   for (const auto &y : x) cerr << setw(10) << y << " ";
  //   cerr << "\n";
  // }
  cout << solve(graph, genes, start) << "\n";

  return 0;
}
