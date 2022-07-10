class Solution {
 public:
  bool isMatch(string s, string p) {
    int p_length = p.length();
    std::vector<bool> states(p_length + 1, false);
    states.front() = true;
    for (const auto& x : s) {
      for (int i = states.size() - 1; i >= 0; --i) {
        if (!states.at(i)) continue;
        states.at(i) = false;
        if (i > 0 && p.at(i - 1) == '*') states.at(i) = true;
        int j = i;
        while (j < p_length && p.at(j) == '*') states.at(++j) = true;
        if (j < p_length && (p.at(j) == x || p.at(j) == '?'))
          states.at(j + 1) = true;
      }
    }
    for (int i = 0; i < p_length; ++i)
      if (p.at(i) == '*' && states.at(i)) states.at(i + 1) = states.at(i);
    return states.back();
  }
};
