#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

constexpr const ll MOD = 1e9 + 7;

// atk only
// atk + def + potential

int solve(vector<int> &allies, vector<int> &atk, vector<int> &def) {
  ll atk_only = 0;
  sort(allies.begin(), allies.end(), greater<int>());
  sort(atk.begin(), atk.end());
  for (int i = 0; i < atk.size() && i < allies.size(); ++i) {  // atk
    if (allies[i] < atk[i]) break;
    atk_only += allies[i] - atk[i];
  }
  int def_idx = 0;
  sort(def.begin(), def.end());
  for (int i = allies.size() - 1; i >= 0 && def_idx < def.size(); --i) {
    if (def[def_idx] >= allies[i])  // ally strength must > enemy defence
      continue;
    allies[i] = 0;
    ++def_idx;
  }
  if (def_idx != def.size()) return atk_only;
  sort(allies.begin(), allies.end(), greater<int>());
  allies.resize(allies.size() - def.size());
  int atk_idx = 0;
  for (int i = allies.size() - 1; i >= 0 && atk_idx < atk.size(); --i) {
    if (atk[atk_idx] > allies[i])  // ally strength must >= enemy attack
      continue;
    allies[i] -= atk[atk_idx];
    ++atk_idx;
  }
  if (atk_idx != atk.size()) return atk_only;
  ll all = 0;
  for (const auto &x : allies) all += x;
  return all > atk_only ? all : atk_only;
}

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int ally_cnt, enemy_cnt;
  cin >> enemy_cnt >> ally_cnt;
  vector<int> allies(ally_cnt), atk, def;
  string category;
  int strength;
  for (int i = 0; i < enemy_cnt; ++i) {
    cin >> category >> strength;
    if (category == "ATK")
      atk.push_back(strength);
    else
      def.push_back(strength);
  }
  for (auto &x : allies) cin >> x;
  cout << solve(allies, atk, def) << "\n";
  return 0;
}