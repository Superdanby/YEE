class Solution {
 public:
  int searchInsert(vector<int>& nums, int target) {
    return int(std::lower_bound(nums.begin(), nums.end(), target) -
               nums.begin());
  }
};