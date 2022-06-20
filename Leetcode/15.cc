class Solution {
 public:
  vector<vector<int>> threeSum(vector<int>& nums) {
    std::vector<std::vector<int>> ans;
    if (nums.empty()) return ans;
    sort(nums.begin(), nums.end());
    for (int i = 0; i < nums.size(); ++i) {
      int ldx = i + 1, rdx = nums.size() - 1;
      while (ldx < rdx) {
        if (nums.at(i) + nums.at(ldx) + nums.at(rdx) > 0)
          --rdx;
        else if (nums.at(i) + nums.at(ldx) + nums.at(rdx) < 0)
          ++ldx;
        else {
          ans.push_back(std::vector{nums.at(i), nums.at(ldx), nums.at(rdx)});
          while (ldx < rdx && nums.at(ldx) == ans.back().at(1)) ++ldx;
          while (ldx < rdx && nums.at(rdx) == ans.back().at(2)) --rdx;
          continue;
        }
      }
      while (i + 1 < nums.size() && nums.at(i) == nums.at(i + 1)) ++i;
    }
    return ans;
  }
};

// class Solution {
//  public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     std::vector<std::vector<int>> ans;
//     if (nums.empty()) return ans;
//     sort(nums.begin(), nums.end());
//     for (int i = 0, prev = nums.front() - 1; i < nums.size(); ++i) {
//       if (prev == nums.at(i)) continue;
//       prev = nums.at(i);
//       int ldx = i + 1, rdx = nums.size() - 1;
//       while (ldx < rdx) {
//         if (nums.at(i) + nums.at(ldx) + nums.at(rdx) > 0)
//           --rdx;
//         else if (nums.at(i) + nums.at(ldx) + nums.at(rdx) < 0)
//           ++ldx;
//         else {
//           ans.push_back(std::vector{nums.at(i), nums.at(ldx), nums.at(rdx)});
//           while (ldx < rdx && nums.at(ldx) == ans.back().at(1)) ++ldx;
//           while (ldx < rdx && nums.at(rdx) == ans.back().at(2)) --rdx;
//           continue;
//         }
//       }
//     }
//     return ans;
//   }
// };

// class Solution {
//  public:
//   vector<vector<int>> threeSum(vector<int>& nums) {
//     std::vector<std::vector<int>> ans;
//     if (nums.empty()) return ans;
//     sort(nums.begin(), nums.end());
//     int prev = nums.front() - 1;
//     for (auto it = nums.begin(); it != nums.end(); ++it) {
//       if (prev == *it) continue;
//       prev = *it;
//       auto lit = it, ub = nums.end();
//       int lprev = *lit - 1;
//       for (++lit; lit - ub < 0;) {
//         if (*lit == lprev) continue;
//         int target = -*it - *lit;
//         auto rit = lit;
//         rit = std::lower_bound(++rit, ub, target);
//         if (rit != ub && target == *rit) {
//           ans.push_back(std::vector{*it, *lit, *rit});
//           ub = rit;
//           lit = std::lower_bound(++lit, ub, -*it - *rit);
//         } else
//           ++lit;
//       }
//     }
//     return ans;
//   }
// };
