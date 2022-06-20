class Solution {
 public:
  vector<string> generateParenthesis(int n) {
    std::vector<std::string> ans;
    gen("", n, n, ans);
    return ans;
  }
  void gen(std::string candidate, int front, int back,
           std::vector<std::string>& ans) {
    if (front + back == 0) {
      ans.emplace_back(candidate);
      return;
    }
    if (front > 0) gen(candidate + '(', front - 1, back, ans);
    if (front < back) gen(candidate + ')', front, back - 1, ans);
  }
};