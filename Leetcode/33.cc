class Solution {
 public:
  int search(vector<int>& nums, int target) {
    if (nums.front() < nums.back())
      return GetIndex(nums.begin(), nums.begin(), nums.end(), target);
    int lb = 0, ub = nums.size() - 1;
    while (ub - lb > 1) {
      int pivot = (ub + lb) / 2;
      if (nums.at(pivot) > nums.back())
        lb = pivot;
      else
        ub = pivot;
    }
    if (target > nums.back())
      return GetIndex(nums.begin(), nums.begin(), nums.begin() + ub, target);
    return GetIndex(nums.begin(), nums.begin() + ub, nums.end(), target);
  }
  int GetIndex(vector<int>::iterator origin, vector<int>::iterator begin,
               vector<int>::iterator end, int target) {
    auto it = std::lower_bound(begin, end, target);
    if (it == end || *it != target) return -1;
    return it - origin;
  }
};