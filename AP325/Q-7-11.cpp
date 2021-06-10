#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

const vector<int> direction{-1, 1};

int root(vector<int> &union_set, const int x) {
  if (union_set[x] == x) return x;
  return union_set[x] = root(union_set, union_set[x]);
}

void safe_merge(vector<int> &union_set, unordered_map<int, int> &val,
                multiset<int> &smallest, int x, int y) {
  if ((x = root(union_set, x)) == (y = root(union_set, y))) return;
  if (y < x) swap(x, y);
  auto it_x = smallest.find(val[x]);
  smallest.erase(it_x);
  auto it_y = smallest.find(val[y]);
  smallest.erase(it_y);
  val[x] += val[y];
  val.erase(y);
  smallest.insert(val[x]);
  union_set[y] = union_set[x];
  return;
}

void record(vector<int> &graph, vector<int> &union_set,
            unordered_map<int, int> &val, multiset<int> &smallest,
            const int i) {
  static int pond_idx = 1;
  ++pond_idx;
  union_set[pond_idx] = pond_idx;
  int size = 0;
  queue<int> que;
  que.push(i);
  graph[i] = pond_idx;
  while (!que.empty()) {
    ++size;
    for (const auto &x : direction) {
      if (graph[que.front() + x] == 1) {
        graph[que.front() + x] = pond_idx;
        que.push(que.front() + x);
      }
    }
    que.pop();
  }
  val[pond_idx] = size;
  smallest.insert(size);
}

void solve(vector<int> &graph, const vector<int> &digs) {
  vector<int> union_set(graph.size());
  unordered_map<int, int> val;
  multiset<int> smallest;
  for (int i = 0; i < graph.size(); ++i)
    if (graph[i] == 1) record(graph, union_set, val, smallest, i);
  // for (const auto &x : smallest) cerr << x << " ";
  // cerr << "\n";

  // for (int i = 0; i < graph.size(); ++i) {
  //   for (int j = 0; j < graph[i].size(); ++j) cerr << graph[i][j] << " ";
  //   cerr << "\n";
  // }
  // for (const auto &x : val) cerr << x.first << " " << x.second << " "; cerr
  // << "\n";

  auto it = smallest.end();
  pair<int, int> ans{*(--it), *(smallest.begin())};
  for (const auto &x : digs) {
    auto dir_it = direction.begin();
    for (; dir_it != direction.end(); ++dir_it) {
      if (graph[x + *dir_it] != 0) break;
    }
    if (dir_it == direction.end())
      record(graph, union_set, val, smallest, x);
    else {
      auto dir_next = dir_it;
      for (++dir_next; dir_next != direction.end(); ++dir_next) {
        if (graph[x + *dir_next] != 0)
          safe_merge(union_set, val, smallest, graph[x + *dir_it],
                     graph[x + *dir_next]);
        // for (const auto &x : val)
        //   cerr << x << " " << x.second << "         ";
        // cerr << "\n";
      }
      graph[x] = root(union_set, graph[x + *dir_it]);
      auto node_val = smallest.find(val[graph[x]]);
      smallest.erase(node_val);
      ++val[graph[x]];
      smallest.insert(val[graph[x]]);
    }
    // for (const auto &x : smallest) cerr << x << " ";
    // cerr << "\n";
    it = smallest.end();
    ans.first += *(--it);
    ans.second += *(smallest.begin());

    // for (const auto &x : val) cerr << x << " " << x.second << " "; cerr
    // << "\n"; for (int i = 0; i < graph.size(); ++i) {
    //   for (int j = 0; j < graph[i].size(); ++j) cerr << graph[i][j] << " ";
    //   cerr << "\n";
    // }
  }
  cout << ans.first << "\n" << ans.second << "\n";
  return;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int size, dig_cnt;
  cin >> size >> dig_cnt;
  vector<int> graph(size + 2);
  for (int i = 1; i < graph.size() - 1; ++i) cin >> graph[i];
  vector<int> digs(dig_cnt);
  for (auto &x : digs) cin >> x;
  solve(graph, digs);

  return 0;
}
