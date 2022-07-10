class Solution {
 public:
  int jump(vector<int>& nums) {
    if (nums.size() < 2) return 0;
    int ans = 0, back = -1, new_back = nums.front();
    for (int i = 0; i < nums.size(); ++i) {
      if (i > back) {
        ++ans;
        back = new_back;
      }
      if (nums.at(i) + i > new_back) new_back = nums.at(i) + i;
    }
    return ans;
  }
};
