class Solution {
 public:
  bool canJump(vector<int>& nums) {
    int right = 0;
    for (int i = 0; i < nums.size(); ++i)
      if (right >= i)
        right = nums.at(i) + i > right ? nums.at(i) + i : right;
      else
        break;
    return right >= nums.size() - 1;
  }
};
