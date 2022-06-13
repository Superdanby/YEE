class Solution {
 public:
  string longestCommonPrefix(vector<string>& strs) {
    std::string ans = strs.front();
    for (const auto& input : strs) {
      int length = 0;
      for (; length < input.length() && length < ans.length(); ++length)
        if (input.at(length) != ans.at(length)) break;
      ans.resize(length);
    }
    return ans;
  }
};