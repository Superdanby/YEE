class Solution {
 public:
  string multiply(string num1, string num2) {
    std::deque<char> num_1(num1.rbegin(), num1.rend()),
        num_2(num2.rbegin(), num2.rend());
    std::vector<std::deque<char>> multiplied;
    multiplied.reserve(10);
    multiplied.push_back({'0'});
    for (int i = 1; i < 10; ++i)
      multiplied.push_back(Add(num_1, multiplied.back()));
    std::deque<char> ans{'0'}, zero{'0'};
    for (const auto &val_char : num2) {
      if (ans != zero) ans.push_front('0');
      ans = Add(ans, multiplied.at(val_char - '0'));
    }
    return {ans.rbegin(), ans.rend()};
  }
  std::deque<char> Add(std::deque<char> num_1, std::deque<char> num_2) {
    while (num_1.size() < num_2.size()) num_1.push_back('0');
    while (num_1.size() > num_2.size()) num_2.push_back('0');
    short carry = 0;
    std::deque<char> ans;
    for (int i = 0; i < num_1.size(); ++i) {
      short val1 = num_1.at(i) - '0', val2 = num_2.at(i) - '0';
      carry = val1 + val2 + carry;
      ans.push_back(carry % 10 + '0');
      carry /= 10;
    }
    if (carry) ans.push_back(carry + '0');
    return ans;
  }
};
