class Solution {
 public:
  int removeDuplicates(vector<int>& nums) {
    int ans = 0, prev = nums.front() - 1, idx = 0;
    for (; idx < nums.size(); ++idx)
      if (nums.at(idx) != prev) prev = nums.at(ans++) = nums.at(idx);
    return ans;
  }
};
