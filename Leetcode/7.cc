class Solution {
 public:
  int reverse(int x) {
    bool positive = x > 0;
    int limit = positive ? std::numeric_limits<int>::max()
                         : std::numeric_limits<int>::min();
    std::deque<short> upper_bound, candidate;
    while (limit) {
      upper_bound.push_front(limit % 10);
      upper_bound.front() =
          upper_bound.front() > 0 ? upper_bound.front() : -upper_bound.front();
      limit /= 10;
    }
    while (x) {
      candidate.push_back(x % 10);
      candidate.back() =
          candidate.back() > 0 ? candidate.back() : -candidate.back();
      x /= 10;
    }
    int ans = 0;
    if (candidate.size() == upper_bound.size())
      for (auto it_can = candidate.cbegin(), it_up = upper_bound.cbegin();
           it_can != candidate.cend(); ++it_can, ++it_up)
        if (*it_can > *it_up)
          return ans;
        else if (*it_can < *it_up)
          break;
    while (!candidate.empty()) {
      ans *= 10;
      ans += candidate.front();
      candidate.pop_front();
    }
    return positive ? ans : -ans;
  }
};
