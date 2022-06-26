class Solution {
 public:
  int longestValidParentheses(string s) {
    int depth = 0, ans = 0;
    std::deque<int> local;  // cnt ()(()
    for (const auto &parentheses : s) {
      if (parentheses == '(') {
        ++depth;
        local.push_back(0);
      } else if (depth) {
        --depth;
        int cnt = 1;
        while (local.size() > depth) {
          cnt += local.back();
          local.pop_back();
        }
        local.push_back(cnt);
        ans = cnt > ans ? cnt : ans;
      } else
        local.clear();
    }
    return ans * 2;
  }
};
