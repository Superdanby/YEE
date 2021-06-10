#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

ll traverse(vector<vector<int>> &graph, vector<int> &costs,
            vector<pair<vector<int>, int>> &state, const int x) {
  if (state[x].second != 0) return state[x].second;
  for (const auto &y : graph[x]) {
    ll cost = traverse(graph, costs, state, y);
    if (cost == state[x].second) {
      state[x].first.push_back(y);
    } else if (cost > state[x].second) {
      state[x].first = {y};
      state[x].second = cost;
    }
  }
  // for (const auto &x : state) cerr << x.first << " " << x.second << "      ";
  // cerr << "\n";
  return state[x].second += costs[x];
}

void solve(vector<vector<int>> &graph, vector<int> &costs,
           unordered_set<int> &starts) {
  vector<pair<vector<int>, int>> state(costs.size(),
                                       {vector<int>(), 0});  // child, cost
  for (const auto &x : starts) traverse(graph, costs, state, x);
  int start = -1, MAX = -1;
  for (const auto &x : starts) {
    if (state[x].second > MAX) {
      start = x;
      MAX = state[x].second;
    }
  }
  // for (const auto &x : state) cerr << x.first << " " << x.second << "      ";
  // cerr << "\n";
  cout << state[start].second << "\n";
  set<int> ans;
  ans.insert(start + 1);
  queue<int> que;
  que.push(start);
  while (!que.empty()) {
    for (const auto &x : state[que.front()].first) {
      ans.insert(x + 1);
      que.push(x);
    }
    que.pop();
  }
  auto it = ans.begin();
  cout << *it;
  for (++it; it != ans.end(); ++it) cout << " " << *it;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int vertex_cnt, edge_cnt;
  cin >> vertex_cnt >> edge_cnt;
  vector<int> costs(vertex_cnt);
  for (auto &x : costs) cin >> x;
  vector<vector<int>> graph(vertex_cnt);
  int from, to;

  unordered_set<int> starts;
  for (int i = 0; i < vertex_cnt; ++i) starts.insert(i);
  for (int i = 0; i < edge_cnt; ++i) {
    cin >> from >> to;
    graph[from - 1].push_back(to - 1);
    starts.erase(to - 1);
  }
  // for (const auto x : starts) cerr << x << " ";
  // cerr << "\n";
  solve(graph, costs, starts);

  return 0;
}
