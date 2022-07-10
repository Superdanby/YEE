class Solution {
 public:
  int maxSubArray(vector<int>& nums) {
    int local = 0, ans = nums.front();
    for (const auto& x : nums) {
      local += x;
      ans = local > ans ? local : ans;
      if (local < 0) local = 0;
    }
    return ans;
  }
};
