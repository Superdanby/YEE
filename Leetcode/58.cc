class Solution {
 public:
  int lengthOfLastWord(string s) {
    auto it = s.rbegin();
    while (it != s.rend() && *it == ' ') ++it;
    int ans = 0;
    while (it != s.rend() && *it != ' ') ++it, ++ans;
    return ans;
  }
};
