class Solution {
 public:
  int threeSumClosest(vector<int>& nums, int target) {
    std::sort(nums.begin(), nums.end());
    int ans = nums.at(0) + nums.at(1) + nums.at(2);
    for (auto it = nums.begin(); it != nums.end(); ++it) {
      auto lit = it, rit = nums.end();
      ++lit, --rit;
      while (lit < rit) {
        if (abs(*it + *lit + *rit - target) < abs(ans - target))
          ans = *it + *lit + *rit;
        if (*it + *lit + *rit > target)
          --rit;
        else if (*it + *lit + *rit < target)
          ++lit;
        else
          return target;
      }
      lit = it;
      while (++lit != nums.end() && *it == *lit) ++it;
    }
    return ans;
  }
};