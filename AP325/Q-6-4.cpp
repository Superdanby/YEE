#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll INF = 1L << 60;

inline ll absolute(const ll &a, const ll &b) { return a > b ? a - b : b - a; }

ll solve(vector<pair<ll, ll>> &stages) {
  stages.push_back({0, 0});
  // for (const auto &x : stages) cerr << x.first << " " << x.second << "\n";
  for (int i = 1; i < stages.size() - 1; ++i) {
    ll temp_fir =
        stages.back().first + absolute(stages[i].first, stages[i - 1].first);
    ll temp_sec =
        stages.back().second + absolute(stages[i].first, stages[i - 1].second);
    ll back_fir = temp_fir < temp_sec ? temp_fir : temp_sec;
    temp_fir =
        stages.back().first + absolute(stages[i].second, stages[i - 1].first);
    temp_sec =
        stages.back().second + absolute(stages[i].second, stages[i - 1].second);
    stages.back().first = back_fir;
    stages.back().second = temp_fir < temp_sec ? temp_fir : temp_sec;
  }
  return stages.back().first < stages.back().second ? stages.back().first
                                                    : stages.back().second;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  ll stage_cnt, start;
  cin >> stage_cnt >> start;
  vector<pair<ll, ll>> stages(stage_cnt + 1);  // weight, value
  auto it = stages.begin();
  it->first = it->second = start;
  for (++it; it != stages.end(); ++it) cin >> it->first >> it->second;
  cout << solve(stages) << "\n";

  return 0;
}
