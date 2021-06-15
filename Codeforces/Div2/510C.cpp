// https://codeforces.com/contest/510/problem/C
#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;
constexpr const int alphabet_cnt = 26;
constexpr const char alphabet_start = 'a';

bool topological_sort(vector<vector<int>> &rules, vector<int> &order,
                      const int node) {
  int node_order = 1;
  for (const auto &x : rules[node]) {
    if (!order[x])  // cycle
      return false;
    if (order[x] == -1) {  // new node
      order[x] = 0;
      if (!topological_sort(rules, order, x)) return false;
    }
    node_order = order[x] + 1 > node_order ? order[x] + 1 : node_order;
  }
  if (!order[node]) order[node] = node_order;
  return true;
}

void solve(vector<string> &strings) {
  // generate rules
  vector<vector<int>> rules(alphabet_cnt);
  for (int i = 1; i < strings.size(); ++i) {
    int j = 0;
    for (; j < strings[i].length() && j < strings[i - 1].length(); ++j) {
      auto from = strings[i - 1][j] - alphabet_start,
           to = strings[i][j] - alphabet_start;
      if (from != to) {
        rules[from].push_back(to);
        break;
      }
    }
    if (strings[i].length() < strings[i - 1].length() &&
        j == strings[i].length()) {
      cout << "Impossible\n";
      return;
    }
  }
  // for (int i = 0; i < rules.size(); ++i) {
  //   cerr << char(i + 'a') << ":";
  //   for (int j = 0; j < rules[i].size(); ++j) {
  //     cerr << " " << char(rules[i][j] + 'a');
  //   }
  //   cerr << "\n";
  // }
  // cerr << "\n";
  vector<int> order(alphabet_cnt, -1);
  for (int i = 0; i < rules.size(); ++i) {
    if (order[i] == -1) order[i] = 0;
    if (!topological_sort(rules, order, i)) {
      cout << "Impossible\n";
      return;
    }
  }
  // for (const auto &x : order) cerr << " " << x;
  // cerr << "\n";
  multimap<int, char, greater<int>> ans;
  for (int i = 0; i < order.size(); ++i) {
    ans.insert({order[i], i + alphabet_start});
  }
  for (const auto &x : ans) cout << x.second;
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int string_cnt;
  cin >> string_cnt;
  vector<string> strings(string_cnt);
  for (auto &x : strings) cin >> x;

  solve(strings);
  return 0;
}