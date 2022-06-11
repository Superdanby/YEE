class Solution {
 public:
  string longestPalindrome(string s) {
    int ans_front = 0, ans_len = 1;
    std::set<int> odd, even;
    for (int back = 0, front; back < s.size(); ++back) {
      auto it_odd = odd.begin();
      while (it_odd != odd.end()) {
        front = *it_odd - (back - *it_odd);
        if (front < 0 || s.at(front) != s.at(back))
          it_odd = odd.erase(it_odd);
        else
          ++it_odd;
      }
      odd.insert(back);
      front = *odd.begin() - (back - *odd.begin());
      if (back - front + 1 > ans_len)
        ans_front = front, ans_len = back - front + 1;

      auto it_even = even.begin();
      while (it_even != even.end()) {
        front = *it_even - (back - *it_even) + 1;
        if (front < 0 || s.at(front) != s.at(back))
          it_even = even.erase(it_even);
        else
          ++it_even;
      }
      even.insert(back);
      front = *even.begin() - (back - *even.begin()) + 1;
      if (back - front + 1 > ans_len)
        ans_front = front, ans_len = back - front + 1;
    }
    return s.substr(ans_front, ans_len);
  }
};
