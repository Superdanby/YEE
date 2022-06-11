class Solution {
 public:
  vector<int> twoSum(vector<int>& nums, int target) {
    std::unordered_map<int64_t, int64_t> num_dict;
    for (int index = 0; index < nums.size(); ++index) {
      int64_t num_1 = nums.at(index);
      auto it = num_dict.find(target - num_1);
      if (it != num_dict.end()) return {int(it->second), index};
      num_dict.insert({num_1, index});
    }
    return {};
  }
};
