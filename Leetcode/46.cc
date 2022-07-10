class Solution {
 public:
  vector<vector<int>> permute(vector<int> &nums) {
    int mask = 0;
    for (int i = 0; i < nums.size(); ++i) mask = mask * 2 + 1;
    std::vector<std::vector<int>> ans;
    std::vector<int> empty{};
    dfs(ans, nums, mask, empty);
    return ans;
  }
  void dfs(std::vector<std::vector<int>> &ans, std::vector<int> &nums, int mask,
           std::vector<int> &candidiates) {
    if (candidiates.size() == nums.size()) {
      ans.push_back(candidiates);
      return;
    }
    for (int i = 0, digit = 1; digit <= mask; ++i, digit *= 2) {
      if (digit & mask) {
        candidiates.push_back(nums.at(i));
        dfs(ans, nums, mask - digit, candidiates);
        candidiates.pop_back();
      }
    }
  }
};
