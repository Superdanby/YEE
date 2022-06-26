class Solution {
 public:
  void nextPermutation(vector<int>& nums) {
    int prev = nums.back();
    auto it = nums.rbegin();
    for (; it != nums.rend(); ++it) {
      if (prev > *it) break;
      prev = *it;
    }
    if (it == nums.rend()) {
      sort(nums.begin(), nums.end());
      return;
    }
    auto replacement = std::lower_bound(nums.rbegin(), it, *it + 1);
    std::swap(*it, *replacement);
    std::sort(nums.rbegin(), it, std::greater());
  }
};
