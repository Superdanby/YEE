class Solution {
  struct Node {
    char value = 0;
    std::vector<int> next;
    bool advance = false;
  };

 public:
  bool isMatch(string s, string p) {
    std::vector<Node> pattern(1);
    pattern.reserve(p.size() + 1);

    for (auto it = p.begin(); it != p.end(); ++it) {
      if (*it == '*') {
        pattern.at(pattern.size() - 2).advance = true;
        pattern.back().next.push_back(pattern.size() - 1);
        continue;
      }
      pattern.push_back({.value = *it});
      pattern.at(pattern.size() - 2).next.push_back(pattern.size() - 1);
    }

    int start = 0;
    std::unordered_set<int> status{start}, next_status;
    while (pattern.at(start).advance) status.insert(++start);

    for (int index = 0; index < s.size(); ++index) {
      for (const auto &state : status) {
        for (auto candidate : pattern.at(state).next) {
          if (s.at(index) == pattern.at(candidate).value ||
              pattern.at(candidate).value == '.') {
            next_status.insert(candidate);
            while (pattern.at(candidate).advance)
              next_status.insert(++candidate);
          }
        }
      }
      status.swap(next_status);
      next_status.clear();
    }
    return status.find(pattern.size() - 1) != status.end();
    // return status.contains(pattern.size() - 1);
  }
};
