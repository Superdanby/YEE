#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

class SegTree {
  // 1-base node, 0-base segment, right-opened interval [,)
  vector<ll> sum, min, diff,
      assign;  // diff: subtree(including the node) needs to be updated
  ll start, ans_sum, ans_min;
  ll MAX = 1LL << 57;

 public:
  SegTree(vector<ll> &inp) {
    this->start = inp.size();
    // this->sum.resize(this->start);
    this->min.resize(this->start, this->MAX);
    // this->sum.insert(this->sum.end(), inp.begin(), inp.end());
    this->min.insert(this->min.end(), inp.begin(), inp.end());
    this->diff.resize(start * 2);
    for (auto node = this->start - 1; node > 0; --node) {
      // this->sum[node] = this->sum[node * 2] + this->sum[node * 2 + 1];
      this->min[node] = this->min[node * 2] < this->min[node * 2 + 1]
                            ? this->min[node * 2]
                            : this->min[node * 2 + 1];
    }
  }
  // void debug() {
  //   cout << "Diff:";
  //   for (const auto &x : this->diff) cerr << " " << x;
  //   cerr << "\n";
  //   cout << "Sum:";
  //   for (const auto &x : this->sum) cerr << " " << x;
  //   cerr << "\n";
  //   cout << "Min:";
  //   for (const auto &x : this->min) cerr << " " << x;
  //   cerr << "\n";
  // }
  void modify(ll left, ll right, ll value) {
    // vector<pair<ll, ll>> sum_que;  // descending
    vector<ll> min_que;  // descending
    for (left += this->start, right += this->start; left < right;
         left /= 2, right /= 2) {
      if (right & 1) {
        --right;
        // sum_que.push_back({right, value});
        min_que.push_back(right), this->min[right] += value;
        if (right < start) {
          this->diff[right * 2] += value;
          this->diff[right * 2 + 1] += value;
          // this->diff[right * 2] += value / 2;
          // this->diff[right * 2 + 1] += value / 2;
        }
      }
      if (left & 1) {
        if (left < start) {
          this->diff[left * 2] += value;
          this->diff[left * 2 + 1] += value;
          // this->diff[left * 2] += value / 2;
          // this->diff[left * 2 + 1] += value / 2;
        }
        // sum_que.push_back({left, value});
        min_que.push_back(left), this->min[left] += value;
        ++left;
      }
      // value *= 2;
    }
    for (size_t i = 0; i < min_que.size();
         ++i) {  // growing vector, don't use iterators
      const auto node = min_que[i];
      if (node / 2 > 0) {
        const auto small = this->min[node] + this->diff[node] <
                                   (this->min[node ^ 1] + this->diff[node ^ 1])
                               ? this->min[node] + this->diff[node]
                               : (this->min[node ^ 1] + this->diff[node ^ 1]);
        if (small != this->min[node / 2]) {
          this->min[node / 2] = small;
          // if (min_que.back() != node / 2), already implied in the if
          // statement above
          min_que.push_back(node / 2);
        }
      }
    }
    // for (size_t i = 0; i < sum_que.size();
    //      ++i) {  // growing vector, don't use iterators
    //   const auto [node, value] = sum_que[i];
    //   this->sum[node] += value;
    //   if (node / 2 > 0) {
    //     if (sum_que.back().first == node / 2)
    //       sum_que.back().second += value;
    //     else
    //       sum_que.push_back({node / 2, value});
    //   }
    // }
  }
  void query(ll left, ll right) {
    vector<ll> que, query_nodes;  // descending
    for (left += this->start, right += this->start; left < right;
         left /= 2, right /= 2) {
      if (right & 1) que.push_back(--right), query_nodes.push_back(right);
      if (left & 1) que.push_back(left), query_nodes.push_back(left++);
    }
    for (size_t i = 0; i < que.size();
         ++i)  // growing vector, don't use iterators
      if (que[i] / 2 != que.back()) que.push_back(que[i] / 2);
    if (!que.back()) que.pop_back();  // always true
    for (auto it = que.rbegin(); it != que.rend(); ++it) {
      const auto node = *(it);
      if (this->diff[node]) {
        // this->sum[node] += this->diff[node];
        this->min[node] += this->diff[node];
        if (node * 2 < this->start * 2) {
          this->diff[node * 2] += this->diff[node];
          this->diff[node * 2 + 1] += this->diff[node];
          // this->diff[node * 2] += this->diff[node] / 2;
          // this->diff[node * 2 + 1] += this->diff[node] / 2;
        }
        this->diff[node] = 0;
      }
    }
    // this->ans_sum = 0;
    // for (const auto &x : query_nodes) this->ans_sum += this->sum[x];
    this->ans_min = this->MAX;
    for (const auto &x : query_nodes)
      this->ans_min =
          this->ans_min < this->min[x] ? this->ans_min : this->min[x];
  }
  ll getStart() { return this->start; }
  // ll getSum() { return this->ans_sum; }
  ll getMin() { return this->ans_min; }
};

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll num_cnt, action_cnt;
  cin >> num_cnt;
  vector<ll> nums(num_cnt);
  for (auto &x : nums) cin >> x;
  SegTree seg_tree(nums);
  // seg_tree.debug();
  cin >> action_cnt;
  ll left, right, value;
  string inp;
  istringstream iss;
  getline(cin, inp);
  while (action_cnt--) {
    getline(cin, inp);
    iss.clear();
    iss.str(inp);
    iss >> left;
    iss >> right;
    // cerr << left << " " << right << " ";
    if (iss >> value) {
      // cerr << value << "\n";
      if (left <= right) {
        seg_tree.modify(left, right + 1, value);
      } else {
        seg_tree.modify(left, seg_tree.getStart(), value);
        seg_tree.modify(0, right + 1, value);
      }
    } else {
      // cerr << "\n";
      if (left <= right)
        seg_tree.query(left, right + 1), cout << seg_tree.getMin() << "\n";
      else {
        seg_tree.query(left, seg_tree.getStart());
        const auto first = seg_tree.getMin();
        seg_tree.query(0, right + 1);
        const auto second = seg_tree.getMin();
        cout << (first < second ? first : second) << "\n";
      }
    }
    // seg_tree.debug();
    // cerr << "\n";
  }
}