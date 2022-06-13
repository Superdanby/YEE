class Solution {
 public:
  string intToRoman(int num) {
    std::vector<std::pair<int, char>> dict{{1, 'I'},   {5, 'V'},   {10, 'X'},
                                           {50, 'L'},  {100, 'C'}, {500, 'D'},
                                           {1000, 'M'}};
    std::string ans;
    for (int index = dict.size() - 1; index >= 0; index -= 2) {
      if (num < dict.at(index).first) continue;
      int times = num / dict.at(index).first;
      num %= dict.at(index).first;
      if (times == 9) {
        ans += dict.at(index).second;
        ans += dict.at(index + 2).second;
        continue;
      }
      if (times > 4) {
        ans += dict.at(index + 1).second;
        times -= 5;
      }
      if (times == 4) {
        ans += dict.at(index).second;
        ans += dict.at(index + 1).second;
        continue;
      }
      while (times--) ans += dict.at(index).second;
    }
    return ans;
  }
};