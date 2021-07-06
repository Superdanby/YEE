#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr const int INF = 0x3f3f3f3f;

inline int SPFA(vector<unordered_map<int, pair<int, int>>> &graph) {
  // find min cost path from S to T
  unordered_set<int> nodes;
  vector<int> costs(graph.size(), INF), flows(graph.size(), INF),
      from(graph.size(), -1);
  costs.front() = 0;
  from.front() = 0;
  nodes.insert(0);
  int min_cost = INF;
  while (!nodes.empty()) {  // don't need to check for negative cycle
    auto node = *(nodes.begin());
    nodes.erase(nodes.begin());
    if (node == graph.size() - 1) continue;
    for (const auto &[to, limit_cost] : graph[node]) {
      const auto &[limit, cost] = limit_cost;
      if (limit > 0 && costs[node] + cost < costs[to]) {
        costs[to] = costs[node] + cost;
        flows[to] = limit < flows[node] ? limit : flows[node];
        from[to] = node;  // record parent node for back tracking
        nodes.insert(to);
      }
    }
  }
  int parent = from.back(), child = graph.size() - 1;
  if (parent == -1) return 0;
  while (child != 0) {
    graph[parent][child].first -= flows.back();
    graph[child][parent].first += flows.back();
    child = parent;
    parent = from[parent];
  }
  // for (const auto &x : from) cerr << setw(12) << x << " ";
  // cerr << "\n";
  // for (const auto &x : flows) cerr << setw(12) << x << " ";
  // cerr << "\n";
  // for (const auto &x : costs) cerr << setw(12) << x << " ";
  // cerr << "\n";
  return flows.back() * costs.back();
}

int solve(vector<unordered_map<int, pair<int, int>>> &graph) {
  int ans = 0, add_cost;
  while (true) {
    if (add_cost = SPFA(graph))
      ans += add_cost;
    else
      break;
  }
  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  string target;
  cin >> target;
  int resource_cnt;
  cin >> resource_cnt;
  unordered_map<char, pair<int, int>> discretize;  // char, index, count
  int discrete_idx = resource_cnt + 1;
  for (const auto &x : target) {
    auto [it, success] = discretize.insert({x, {discrete_idx, 1}});
    if (success)
      ++discrete_idx;
    else
      ++((it->second).second);
  }
  string inp;
  int limit;
  vector<unordered_map<int, pair<int, int>>> graph(
      1 + resource_cnt + discretize.size() + 1);  // to, {limit, cost}
  for (int i = 0; i < resource_cnt; ++i) {
    cin >> inp >> limit;
    graph.front().insert({1 + i, {limit, 0}});
    graph[1 + i].insert({0, {0, 0}});
    for (const auto &x : inp) {
      auto [it, success] =
          graph[1 + i].insert({discretize[x].first, {1, i + 1}});
      if (!success) ++(it->second).first;
      graph[discretize[x].first].insert({1 + i, {0, -i - 1}});
    }
  }
  for (const auto &[_, index_count] : discretize) {
    const auto &[index, count] = index_count;
    graph[index].insert({graph.size() - 1, {count, 0}});
    graph[graph.size() - 1].insert({index, {0, 0}});
  }

  int ans = solve(graph);
  // for (int i = 0; i < graph.size(); ++i) {
  //   cerr << i << ": ";
  //   for (const auto &x: graph[i])
  //     cout << x.first << " " << x.second.first << " " << x.second.second << "
  //     ";
  //   cerr << "\n";
  // }
  // cerr << "\n";

  int expect = target.length();
  for (const auto &[_, flow__] : graph.back()) expect -= flow__.first;
  if (expect)
    cout << "-1";
  else
    cout << ans;
  cout << "\n";
  return 0;
}