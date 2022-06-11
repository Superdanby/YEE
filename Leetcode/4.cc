class Solution {
 public:
  double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
    if (nums1.size() < nums2.size()) nums1.swap(nums2);
    if (nums1.empty()) return 0;
    if (nums2.empty()) {
      if (nums1.size() & 1) return nums1.at(nums1.size() / 2);
      return (double(nums1.at(nums1.size() / 2)) +
              double(nums1.at(nums1.size() / 2 - 1))) /
             2;
    }
    int lb = -1, ub = nums2.size(),
        inner_count = (nums1.size() + nums2.size()) / 2 + 1;
    while (ub - lb > 1) {
      int pivot = (lb + ub) / 2;
      if (IsCandidate(nums1, nums2, pivot, inner_count))
        ub = pivot;
      else
        lb = pivot;
    }
    if ((nums1.size() + nums2.size()) & 1) {
      if (ub == 0) return nums1.at(inner_count - 1);
      if (ub == inner_count) return nums2.at(inner_count - 1);
      return nums2.at(ub - 1) > nums1.at(inner_count - ub - 1)
                 ? nums2.at(ub - 1)
                 : nums1.at(inner_count - ub - 1);
    }
    if (ub == 0)
      return (double(nums1.at(inner_count - 1)) +
              double(nums1.at(inner_count - 2))) /
             2;
    if (ub == inner_count)
      return (double(nums2.at(inner_count - 1)) +
              double(nums2.at(inner_count - 2))) /
             2;
    std::vector<double> candidates{double(nums1.at(inner_count - ub - 1)),
                                   double(nums2.at(ub - 1))};
    if (inner_count - ub - 2 >= 0)
      candidates.push_back(nums1.at(inner_count - ub - 2));
    if (ub - 2 >= 0) candidates.push_back(nums2.at(ub - 2));
    std::sort(candidates.begin(), candidates.end(), std::greater());
    return (candidates.at(0) + candidates.at(1)) / 2;
  }
  bool IsCandidate(std::vector<int>& nums1, std::vector<int>& nums2,
                   int count_2, int inner_count) {
    if (count_2 >= nums2.size()) return true;
    if (inner_count - count_2 > nums1.size()) return false;
    return nums2.at(count_2) >= nums1.at(inner_count - count_2 - 1);
  }
};
