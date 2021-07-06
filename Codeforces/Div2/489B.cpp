#include <bits/stdc++.h>

using namespace std;

// int solve(vector<int> &boys, vector<int>&girls) {
//   sort(boys.begin(), boys.end());
//   sort(girls.begin(), girls.end());
//   int boy_idx = 0, girl_idx = 0, ans = 0;
//   while (boy_idx < boys.size() && girl_idx < girls.size()) {
//     if (boys[boy_idx] - girls[girl_idx] < 2 && girls[girl_idx] -
//     boys[boy_idx] < 2)
//       ++ans, ++boy_idx, ++girl_idx;
//     else if (boys[boy_idx] < girls[girl_idx]) ++boy_idx;
//     else ++girl_idx;
//   }
//   return ans;
// }

bool augment(vector<unordered_set<int>> &graph, vector<int> &match,
             vector<int> &visited, const int visit, const int node) {
  visited[node] = visit;
  for (const auto &x : graph[node]) {
    // augmenting path found if at least one child node is not matched before
    if (match[x] == -1 || (visited[match[x]] != visit &&
                           augment(graph, match, visited, visit, match[x]))) {
      match[node] = x;
      match[x] = node;
      return true;
    }
  }
  return false;
}

int solve(vector<int> &boys, vector<int> &girls) {
  vector<unordered_set<int>> graph(boys.size() + girls.size());
  sort(boys.begin(), boys.end());
  sort(girls.begin(), girls.end());

  int girl_start = boys.size();
  for (int boy_idx = 0, girl_front = 0; boy_idx < boys.size(); ++boy_idx) {
    for (int girl_idx = girl_front; girl_idx < girls.size(); ++girl_idx) {
      if (boys[boy_idx] - girls[girl_idx] < 2 &&
          girls[girl_idx] - boys[boy_idx] < 2) {
        graph[boy_idx].insert(girl_idx + girl_start);
        graph[girl_idx + girl_start].insert(boy_idx);
      }
      if (girls[girl_idx] - boys[boy_idx] > 1)
        break;
      else if (boys[boy_idx] - girls[girl_idx] > 1)
        girl_front = girl_idx + 1;
    }
  }

  vector<int> match(graph.size(), -1);
  vector<int> visited(graph.size(), -1);
  int ans = 0;
  for (int i = 0; i < match.size(); ++i)
    if (match[i] == -1)  // never visited
      if (augment(graph, match, visited, i, i)) ++ans;

  return ans;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int boy_cnt, girl_cnt;
  cin >> boy_cnt;
  vector<int> boys(boy_cnt);
  for (auto &x : boys) cin >> x;
  cin >> girl_cnt;
  vector<int> girls(girl_cnt);
  for (auto &x : girls) cin >> x;
  cout << solve(boys, girls) << "\n";
}