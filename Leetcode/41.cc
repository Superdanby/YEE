class Solution {
 public:
  int firstMissingPositive(vector<int>& nums) {
    for (int i = 0; i < nums.size(); ++i) {
      int64_t prev = 0, j = i, temp;
      while (j >= 0 && j < nums.size() && nums.at(j) != j + 1) {
        temp = prev;
        prev = nums.at(j);
        nums.at(j) = temp;
        j = prev - 1;
      }
    }
    for (int i = 0; i < nums.size(); ++i)
      if (!nums.at(i)) return i + 1;
    return nums.size() + 1;
  }
};
