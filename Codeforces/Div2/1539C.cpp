#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int student_cnt;
  ll addtional_cnt, gap;
  cin >> student_cnt >> addtional_cnt >> gap;
  vector<ll> students(student_cnt);
  for (auto &x : students) cin >> x;
  sort(students.begin(), students.end());
  multiset<ll> need;
  ll ans = 1;
  for (int i = 1; i < students.size(); ++i) {
    if (students[i] - students[i - 1] > gap) {
      ++ans;
      need.insert((students[i] - students[i - 1] - 1) / gap);
    }
  }
  for (const auto &x : need) {
    if (addtional_cnt - x >= 0) {
      addtional_cnt -= x;
      --ans;
    }
  }

  cout << ans << "\n";

  return 0;
}