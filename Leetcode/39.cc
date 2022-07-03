class Solution {
 public:
  vector<vector<int>> combinationSum(vector<int> &candidates, int target) {
    std::vector<bool> dp(target + 1);
    dp.front() = true;
    for (int i = 0; i <= target; ++i)
      for (const auto &num : candidates)
        if (i - num >= 0 && dp.at(i - num)) dp.at(i) = true;
    std::deque<std::pair<int, std::vector<int>>> combinations{{target, {}}};
    std::vector<std::vector<int>> ans;
    while (!combinations.empty()) {
      auto [remaining, combination] = combinations.front();
      combinations.pop_front();
      for (const auto &num : candidates) {
        if (!combination.empty() && combination.back() > num) continue;
        int new_remaining = remaining - num;
        if (!new_remaining) {
          ans.push_back(combination);
          ans.back().push_back(num);
        } else if (new_remaining > 0 && dp.at(new_remaining)) {
          combinations.push_back({new_remaining, combination});
          combinations.back().second.push_back(num);
        }
      }
    }
    return ans;
  }
};