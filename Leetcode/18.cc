class Solution {
 public:
  vector<vector<int>> fourSum(vector<int>& nums, int target) {
    sort(nums.begin(), nums.end());
    std::vector<std::vector<int>> ans;
    for (int i = 0; i < nums.size(); ++i) {
      for (int j = i + 1; j < nums.size(); ++j) {
        for (int k = j + 1, l = nums.size() - 1; k < l;) {
          if (int64_t(nums.at(i)) + int64_t(nums.at(j)) + int64_t(nums.at(k)) +
                  int64_t(nums.at(l)) >
              target)
            --l;
          else if (int64_t(nums.at(i)) + int64_t(nums.at(j)) +
                       int64_t(nums.at(k)) + int64_t(nums.at(l)) <
                   target)
            ++k;
          else {
            ans.emplace_back(
                std::vector{nums.at(i), nums.at(j), nums.at(k), nums.at(l)});
            while (k < l && nums.at(k) == ans.back().at(2)) ++k;
            while (k < l && nums.at(l) == ans.back().at(3)) --l;
          }
          while (j + 1 < nums.size() && nums.at(j) == nums.at(j + 1)) ++j;
        }
        while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1)) ++i;
      }
    }
    return ans;
  }
};