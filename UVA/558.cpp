#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
constexpr const int INF = 0x3f3f3f3f;

// Valid but slower
// bool SPFA(vector<unordered_map<int, int>> &graph, vector<bool> &visited,
// const int start) {
//   vector<int> distance(graph.size(), INF), count(graph.size());
//   priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int,
//   int>> > pq; // distance, node pq.push({0, start}); distance[start] = 0;
//   ++count[start];
//   while (!pq.empty()) {
//     auto x = pq.top(); pq.pop();
//     if (distance[x.second] < x.first) continue;
//     for (const auto &y: graph[x.second]) {
//       if (distance[x.second] + y.second < distance[y.first]) {
//         distance[y.first] = distance[x.second] + y.second;
//         if (++count[y.first] == graph.size())
//           return false;
//         pq.push({distance[y.first], y.first});
//       }
//     }
//   }
//   return true;
// }

bool SPFA(vector<unordered_map<int, int>> &graph, vector<bool> &visited,
          const int start) {
  unordered_set<int> updated, next;
  vector<int> distance(graph.size(), INF);
  distance[start] = 0;
  updated.insert(start);
  int negative_cycle = graph.size();
  while (!updated.empty()) {
    for (const auto &x : updated) {
      visited[x] = true;
      for (const auto &y : graph[x]) {
        if (distance[x] + y.second < distance[y.first]) {
          distance[y.first] = distance[x] + y.second;
          next.insert(y.first);
        }
      }
    }
    updated.clear();
    updated.swap(next);
    if (--negative_cycle < 0) return false;
  }
  return true;
}

void solve(vector<unordered_map<int, int>> &graph) {
  vector<bool> visited(graph.size());
  for (int i = 0; i < graph.size(); ++i) {
    if (visited[i]) continue;
    if (!SPFA(graph, visited, i)) {
      cout << "possible\n";
      return;
    }
  }
  cout << "not possible\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);
  int cases;
  cin >> cases;
  while (cases--) {
    int node_cnt, edge_cnt;
    cin >> node_cnt >> edge_cnt;
    vector<unordered_map<int, int>> graph(node_cnt);  // to, cost
    int from, to, cost;
    for (int i = 0; i < edge_cnt; ++i) {
      cin >> from >> to >> cost;
      // auto [it, success] = graph[from].insert({to, cost});
      // if (!success)
      //   it->second = cost < it->second ? cost : it->second;
      auto x = graph[from].insert({to, cost});
      if (!x.second)
        (x.first)->second = cost < (x.first)->second ? cost : (x.first)->second;
    }
    solve(graph);
  }

  return 0;
}