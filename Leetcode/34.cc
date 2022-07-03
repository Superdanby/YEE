class Solution {
 public:
  vector<int> searchRange(vector<int>& nums, int target) {
    auto lit = std::lower_bound(nums.begin(), nums.end(), target);
    if (lit == nums.end() || *lit != target) return {-1, -1};
    auto rit = std::upper_bound(nums.begin(), nums.end(), target) - 1;
    return {int(lit - nums.begin()), int(rit - nums.begin())};
  }
};