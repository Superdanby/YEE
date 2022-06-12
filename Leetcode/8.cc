class Solution {
 public:
  int myAtoi(string s) {
    bool positive = true;
    std::deque<short> upper_bound, candidate;
    int index = 0;
    for (; index < s.size(); ++index) {
      if (s.at(index) == '+') {
        break;
      } else if (s.at(index) == '-') {
        positive = false;
        break;
      } else if (s.at(index) - '0' < 10 && s.at(index) - '0' >= 0) {
        --index;
        break;
      } else if (s.at(index) != ' ')
        return 0;
    }
    int limit = positive ? std::numeric_limits<int>::max()
                         : std::numeric_limits<int>::min();
    int ans = limit;
    while (limit) {
      upper_bound.push_front(limit % 10);
      upper_bound.front() =
          upper_bound.front() > 0 ? upper_bound.front() : -upper_bound.front();
      limit /= 10;
    }
    for (++index; index < s.size(); ++index) {
      if (s.at(index) - '0' > 9 || s.at(index) - '0' < 0) break;
      candidate.push_back(s.at(index) - '0');
    }
    while (!candidate.empty() && candidate.front() == 0) candidate.pop_front();
    if (candidate.size() > upper_bound.size()) return ans;
    if (candidate.size() == upper_bound.size())
      for (auto it_can = candidate.cbegin(), it_up = upper_bound.cbegin();
           it_can != candidate.cend(); ++it_can, ++it_up)
        if (*it_can > *it_up)
          return ans;
        else if (*it_can < *it_up)
          break;
    ans = 0;
    while (!candidate.empty()) {
      ans *= 10;
      ans += positive ? candidate.front() : -candidate.front();
      candidate.pop_front();
    }
    return ans;
  }
};
