class Solution {
 public:
  int romanToInt(string s) {
    std::unordered_map<char, int> dict{{'I', 1},   {'V', 5},   {'X', 10},
                                       {'L', 50},  {'C', 100}, {'D', 500},
                                       {'M', 1000}};
    int ans = 0, prev = 0, value;
    for (const auto& input : s) {
      value = dict.at(input);
      if (prev < value)
        ans += (value - prev * 2);
      else
        ans += value;
      prev = value;
    }
    return ans;
  }
};