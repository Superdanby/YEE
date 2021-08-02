#include <bits/stdc++.h>

using namespace std;

class Trie {
  vector<vector<int>> nodes;
  vector<int> visit_cnt, ending_cnt;
  queue<int> reuse;
  int base;

  int new_node() {
    if (this->reuse.size()) {
      const auto idx = this->reuse.front();
      this->reuse.pop();
      return idx;
    }
    this->nodes.emplace_back(vector<int>(this->base));
    this->visit_cnt.emplace_back(0);
    this->ending_cnt.emplace_back(0);
    return this->nodes.size() - 1;
  }

 public:
  Trie(int base) {
    this->base = base;
    this->nodes.emplace_back(vector<int>(base));
    this->visit_cnt.resize(1);
    this->ending_cnt.resize(1);
  }
  void debug() {
    int i = -1;
    for (const auto& x : this->nodes) {
      cout << ++i << ":";
      for (const auto& y : x) cout << " " << y;
      cout << "\n";
    }
    for (const auto& x : this->visit_cnt) cout << " " << x;
    cout << "\n";
    for (const auto& x : this->ending_cnt) cout << " " << x;
    cout << "\n";
  }
  void insert(int value) {
    int mask = 1 << 30, node = 0;
    for (; mask; node = this->nodes[node][(mask & value) != 0], mask >>= 1) {
      if (!this->nodes[node][(mask & value) != 0])
        this->nodes[node][(mask & value) != 0] = this->new_node();
      ++this->visit_cnt[node];
    }
    ++this->visit_cnt[node];
    ++this->ending_cnt[node];
  }
  void remove(int value) {  // no safe check
    int mask = 1 << 30, node = 0;
    for (int next_node; mask; node = next_node, mask >>= 1) {
      --this->visit_cnt[node];
      if (this->visit_cnt[next_node = this->nodes[node][(mask & value) != 0]] ==
          1)
        this->nodes[node][(mask & value) != 0] = 0;
    }
    --this->visit_cnt[node], --this->ending_cnt[node];
    if (this->visit_cnt[node] == 0) this->reuse.push(node);
  }
  int query(int value) {
    int mask = 1 << 30, node = 0, match = 0;
    for (int next_node; mask; node = next_node, mask >>= 1) {
      match <<= 1;
      if (!this->nodes[node][0])
        next_node = this->nodes[node][1], ++match;
      else if (!this->nodes[node][1])
        next_node = this->nodes[node][0];
      else if (value & mask)
        next_node = this->nodes[node][0];
      else
        next_node = this->nodes[node][1], ++match;
    }
    return match ^ value;
  }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int input_cnt;
  cin >> input_cnt;
  char op;
  int value;
  Trie trie(2);
  trie.insert(0);
  while (input_cnt--) {
    cin >> op >> value;
    if (op == '+')
      trie.insert(value);
    else if (op == '-')
      trie.remove(value);
    else
      cout << trie.query(value) << "\n";
    // trie.debug();
  }
}