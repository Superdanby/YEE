class Solution {
 public:
  int removeElement(vector<int>& nums, int val) {
    int ans = 0;
    for (int idx = 0; idx < nums.size(); ++idx, ++ans) {
      if (nums.at(idx) != val)
        nums.at(ans) = nums.at(idx);
      else
        --ans;
    }
    return ans;
  }
};
