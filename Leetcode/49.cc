class Solution {
 public:
  vector<vector<string>> groupAnagrams(vector<string> &strs) {
    std::vector<std::vector<std::string>> ans;
    std::map<std::vector<int>, int> dict;  // value, group index
    for (const auto &str : strs) {
      std::vector<int> values(26);
      for (const auto &x : str) ++values.at(x - 'a');
      auto [it, success] = dict.insert({values, ans.size()});
      if (success)
        ans.push_back({std::move(str)});
      else
        ans.at(it->second).push_back(std::move(str));
    }
    return ans;
  }
};
