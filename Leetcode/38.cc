class Solution {
 public:
  string countAndSay(int n) {
    std::string ans("1");
    while (--n) ans = Transform(ans);
    return ans;
  }
  std::string Transform(std::string_view before) {
    char prev = before.front();
    int cnt = 0;
    std::string after;
    for (const auto &digit : before) {
      if (prev != digit) {
        after.append(std::to_string(cnt));
        cnt = 0;
        after.push_back(prev);
      }
      ++cnt;
      prev = digit;
    }
    after.append(std::to_string(cnt));
    after.push_back(prev);
    return after;
  }
};