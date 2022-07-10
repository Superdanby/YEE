class Solution {
 public:
  vector<vector<int>> permuteUnique(vector<int> &nums) {
    std::unordered_map<int, int> dict;
    for (const auto &num : nums) {
      auto [it, _] = dict.insert({num, 0});
      ++it->second;
    }
    std::vector<std::vector<int>> ans;
    std::vector<int> empty{};
    dfs(ans, dict, empty, nums.size());
    return ans;
  }
  void dfs(std::vector<std::vector<int>> &ans,
           std::unordered_map<int, int> &dict, std::vector<int> &candidiates,
           int size) {
    if (candidiates.size() == size) {
      ans.push_back(candidiates);
      return;
    }

    for (auto it = dict.begin(); it != dict.end(); ++it) {
      if (it->second) {
        candidiates.push_back(it->first);
        --it->second;
        dfs(ans, dict, candidiates, size);
        candidiates.pop_back();
        ++it->second;
      }
    }
  }
};
