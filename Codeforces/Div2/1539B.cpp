#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int size, query_cnt;
  cin >> size >> query_cnt;
  string inp;
  cin >> inp;
  vector<int> prefix_sum(inp.length() + 1);
  for (int i = 1; i < prefix_sum.size(); ++i)
    prefix_sum[i] = inp[i - 1] - 'a' + 1;

  for (int i = 1; i < prefix_sum.size(); ++i)
    prefix_sum[i] += prefix_sum[i - 1];

  int front, back;
  while (query_cnt--) {
    cin >> front >> back;
    cout << prefix_sum[back] - prefix_sum[front - 1] << "\n";
  }

  return 0;
}