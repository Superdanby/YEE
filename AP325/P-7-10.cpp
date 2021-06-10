#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

// constexpr const int INF = 0x3f3f3f3f;
constexpr const ll INF = 1L << 60;
constexpr const ll MOD = 1e9 + 9;

const vector<pair<int, int>> direction{{-1, 0}, {1, 0}, {0, -1}, {0, 1}};

int root(vector<int> &union_set, const int x) {
  if (union_set[x] == x) return x;
  return union_set[x] = root(union_set, union_set[x]);
}

void safe_merge(vector<int> &union_set, unordered_map<int, int> &val, int x,
                int y) {
  if ((x = root(union_set, x)) == (y = root(union_set, y))) return;
  if (y < x) swap(x, y);
  val[x] += val[y];
  val.erase(y);
  union_set[y] = union_set[x];
  return;
}

void record(vector<vector<int>> &graph, vector<int> &union_set,
            unordered_map<int, int> &val, const int i, const int j) {
  static int pond_idx = 1;
  ++pond_idx;
  union_set[pond_idx] = pond_idx;
  int size = 0;
  queue<pair<int, int>> que;
  que.push({i, j});
  graph[i][j] = pond_idx;
  while (!que.empty()) {
    ++size;
    for (const auto &x : direction) {
      if (graph[que.front().first + x.first][que.front().second + x.second] ==
          1) {
        graph[que.front().first + x.first][que.front().second + x.second] =
            pond_idx;
        que.push({que.front().first + x.first, que.front().second + x.second});
      }
    }
    que.pop();
  }
  val[pond_idx] = size;
}

void solve(vector<vector<int>> &graph, const vector<pair<int, int>> &digs) {
  vector<int> union_set(graph.size() * graph.front().size());
  unordered_map<int, int> val;
  int largest_size = 0;
  for (int i = 0; i < graph.size(); ++i) {
    for (int j = 0; j < graph[i].size(); ++j) {
      if (graph[i][j] == 1) record(graph, union_set, val, i, j);
    }
  }
  // for (int i = 0; i < graph.size(); ++i) {
  //   for (int j = 0; j < graph[i].size(); ++j) cerr << graph[i][j] << " ";
  //   cerr << "\n";
  // }
  for (const auto &x : val)
    largest_size = x.second > largest_size ? x.second : largest_size;
  pair<int, int> ans{largest_size, val.size()};
  // for (const auto &x : val) cerr << x.first << " " << x.second << " "; cerr
  // << "\n";
  for (const auto &x : digs) {
    if (graph[x.first][x.second] == 0) {
      auto dir_it = direction.begin();
      for (; dir_it != direction.end(); ++dir_it) {
        if (graph[x.first + dir_it->first][x.second + dir_it->second] != 0)
          break;
      }
      if (dir_it == direction.end())
        record(graph, union_set, val, x.first, x.second);
      else {
        auto dir_next = dir_it;
        for (++dir_next; dir_next != direction.end(); ++dir_next) {
          if (graph[x.first + dir_next->first][x.second + dir_next->second] !=
              0)
            safe_merge(
                union_set, val,
                graph[x.first + dir_it->first][x.second + dir_it->second],
                graph[x.first + dir_next->first][x.second + dir_next->second]);
          // for (const auto &x : val)
          //   cerr << x.first << " " << x.second << "         ";
          // cerr << "\n";
        }
        graph[x.first][x.second] =
            root(union_set,
                 graph[x.first + dir_it->first][x.second + dir_it->second]);
        ++val[graph[x.first][x.second]];
      }
      largest_size = val[graph[x.first][x.second]] > largest_size
                         ? val[graph[x.first][x.second]]
                         : largest_size;
    }
    ans.first += largest_size;
    ans.second += val.size();

    // for (const auto &x : val) cerr << x.first << " " << x.second << " "; cerr
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

  int row_cnt, col_cnt, dig_cnt;
  cin >> row_cnt >> col_cnt >> dig_cnt;
  vector<vector<int>> graph(row_cnt + 2, vector<int>(col_cnt + 2));
  for (int i = 1; i < graph.size() - 1; ++i)
    for (int j = 1; j < graph[i].size() - 1; ++j) cin >> graph[i][j];
  vector<pair<int, int>> digs(dig_cnt);
  for (auto &x : digs) cin >> x.first >> x.second;
  solve(graph, digs);

  return 0;
}
