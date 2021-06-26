#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
constexpr const ll INF = 1LL << 57;

class Edge {
  int constant;
  int dividend;
  int min_start;
  int to;

 public:
  Edge(int to, int constant, int dividend) {
    this->to = to;
    this->constant = constant;
    this->dividend = dividend;
    ll lb = 1, ub = dividend;
    while (ub - lb > 1) {
      ll pivot = (lb + ub) / 2;
      if (pivot * pivot >= dividend)
        ub = pivot;
      else
        lb = pivot;
    }
    this->min_start = ub - 1;
    // cerr << this->to << " " << this->constant << " " << this->dividend << " "
    // << this->min_start << "\n";
  }
  ~Edge() {}
  ll GetTime(ll now) const {
    ll start = now > this->min_start ? now : this->min_start;
    return start + this->constant + dividend / (start + 1);
  }
  int GetTo() const { return this->to; }
};

ll solve(vector<vector<Edge>> &graph, const int start, const int tail) {
  vector<ll> duration(graph.size(), INF);
  duration[start] = 0;
  priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>>
      pq;  // duration, node
  pq.push({0, 0});
  while (!pq.empty()) {
    const auto [elapsed, node] = pq.top();
    pq.pop();
    const auto now = duration[node];
    if (elapsed > now)
      continue;  // a better solution for node is still in priority queue
    if (node == tail) break;  // tail is the smallest node
    for (const auto &x : graph[node]) {
      const auto next_duration = x.GetTime(now);
      const auto next = x.GetTo();
      if (next_duration < duration[next]) {
        duration[next] = next_duration;
        pq.push({duration[next], next});
      }
    }
  }
  return duration[tail] != INF ? duration[tail] : -1;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int node_cnt, edge_cnt;
  cin >> node_cnt >> edge_cnt;
  vector<vector<Edge>> graph(node_cnt);  // to, cost
  int from, to, constant, dividend;
  for (int i = 0; i < edge_cnt; ++i) {
    cin >> from >> to >> constant >> dividend;
    --from, --to;
    graph[from].emplace_back(Edge(to, constant, dividend));
    graph[to].emplace_back(Edge(from, constant, dividend));
  }
  cout << solve(graph, 0, node_cnt - 1) << "\n";

  return 0;
}