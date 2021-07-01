#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

void tarjan(vector<vector<int>> &graph, vector<bool> &in_subtree,
            stack<int> &subtree, vector<int> &order, vector<int> &cscc,
            vector<int> &scc, const int node) {
  static int accumulate = 0;
  static int scc_cnt = 0;
  order[node] = cscc[node] = ++accumulate;
  in_subtree[node] = true;
  subtree.push(node);
  for (const auto &x : graph[node]) {
    if (!order[x]) {  // new node
      tarjan(graph, in_subtree, subtree, order, cscc, scc, x);
      cscc[node] = cscc[x] < cscc[node] ? cscc[x] : cscc[node];
    } else if (in_subtree[x]) {  // ancestor
      cscc[node] = order[x] < cscc[node] ? order[x] : cscc[node];
    }
  }

  if (order[node] == cscc[node]) {  // subtree root
    while (!subtree.empty() && order[subtree.top()] >= order[node]) {
      in_subtree[subtree.top()] = false;
      // cscc[subtree.top()] = order[node]; // can't ensure topological order
      scc[subtree.top()] = scc_cnt;
      subtree.pop();
    }
    ++scc_cnt;
  }
}

void solve(vector<vector<int>> &graph) {
  // for (int i = 0 ; i < graph.size(); ++i) {
  //   cerr << i << ":";
  //   for (const auto &x : graph[i])
  //     cerr << " " << x;
  //   cerr << "\n";
  // }
  vector<int> order(graph.size()), cscc(graph.size()), scc(graph.size());
  vector<bool> in_subtree(graph.size());
  stack<int> subtree;
  for (int i = 0; i < graph.size(); ++i) {
    if (!order[i]) tarjan(graph, in_subtree, subtree, order, cscc, scc, i);
  }
  bool bad_luck = false;
  for (int i = 0; i < graph.size();
       i += 2) {  // x & ~x should not be in the same SCC
    if (cscc[i] == cscc[i + 1]) bad_luck = true;
  }
  if (bad_luck) {
    cout << "bad luck\n";
    return;
  }

  // for (int i = 0 ; i < graph.size(); ++i)
  //   cerr << setw(4) << i << " ";
  // cerr << "\n";
  // for (const auto &x: order) cerr << setw(4) << x << " ";
  // cerr << "\n";
  // for (const auto &x: cscc) cerr << setw(4) << x << " ";
  // cerr << "\n";

  bool space = false;
  for (int i = 4; i < graph.size(); i += 2) {
    if (scc[i] < scc[i + 1]) {  // set values in reversed topological order
      if (space)
        cout << " ";
      else
        space = true;
      cout << i / 4;
      if (i % 4 < 2)
        cout << 'h';
      else
        cout << 'w';
    }
  }
  cout << "\n";
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int couple_cnt, avoid_cnt;
  while (cin >> couple_cnt >> avoid_cnt) {
    if (!couple_cnt && !avoid_cnt) break;
    vector<vector<int>> graph(couple_cnt * 2 *
                              2);  // husband side bride, husband side groom,
                                   // wife side bride, wife side groom
    graph[3].push_back(2);         // 0w at bride side
    graph[0].push_back(1);         // 0h at groom side
    for (int i = 0; i < graph.size(); i += 4) {
      graph[i].push_back(i + 3);      // husband side bride, wife side groom
      graph[i + 1].push_back(i + 2);  // wife side bride, husband side groom
      graph[i + 2].push_back(i + 1);  // wife side bride, husband side groom
      graph[i + 3].push_back(i);      // husband side bride, wife side groom
    }
    int fir_idx, sec_idx;
    char fir_sex, sec_sex;
    for (int i = 0; i < avoid_cnt; ++i) {
      cin >> fir_idx >> fir_sex >> sec_idx >> sec_sex;
      // adulterous relationships should be at bride side
      graph[4 * fir_idx + (fir_sex == 'w' ? 2 : 0) + 1].push_back(
          4 * sec_idx + (sec_sex == 'w' ? 2 : 0));
      graph[4 * sec_idx + (sec_sex == 'w' ? 2 : 0) + 1].push_back(
          4 * fir_idx + (fir_sex == 'w' ? 2 : 0));
    }
    solve(graph);
  }

  return 0;
}