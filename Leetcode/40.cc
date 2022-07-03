class Solution {
 public:
  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
    std::unordered_map<int, int> dict;
    for (const auto& x : candidates) {
      auto [it, _] = dict.insert({x, 0});
      ++it->second;
    }
    std::vector<std::vector<int>> combinations;
    std::vector<int> empty;
    Generate(dict.begin(), dict.end(), target, empty, combinations);
    return combinations;
  }
  void Generate(std::unordered_map<int, int>::iterator it,
                std::unordered_map<int, int>::iterator end, int value,
                std::vector<int>& combination,
                std::vector<std::vector<int>>& combinations) {
    if (it == end) return;
    for (int i = 0; i <= it->second; ++i) {
      int new_value = value - i * it->first;
      if (new_value < 0) break;
      auto new_it = it;
      for (int j = 0; j < i; ++j) combination.push_back(it->first);
      if (new_value == 0)
        combinations.push_back(combination);
      else
        Generate(++new_it, end, new_value, combination, combinations);
      for (int j = 0; j < i; ++j) combination.pop_back();
    }
  }
};