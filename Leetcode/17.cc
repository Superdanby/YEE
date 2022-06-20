class Solution {
 public:
  vector<string> letterCombinations(string digits) {
    std::vector<std::string> alphabets{"",    "",    "abc",  "def", "ghi",
                                       "jkl", "mno", "pqrs", "tuv", "wxyz"};
    std::vector<std::string> ans, appends;
    if (digits.empty()) return ans;
    int reserve_size = 4;
    for (int i = 1; i < digits.size(); ++i) reserve_size *= 4;
    ans.reserve(reserve_size);
    appends.reserve(reserve_size);
    ans.push_back("");
    for (const auto &digit : digits) {
      for (const auto &alphabet : alphabets.at(digit - '0'))
        for (const auto &prefix : ans)
          appends.push_back(prefix + alphabet);
      ans.swap(appends);
      appends.clear();
    }
    return ans;
  }
};