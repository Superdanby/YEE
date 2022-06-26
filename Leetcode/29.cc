class Solution {
 public:
  int divide(int dividend, int divisor) {
    if (dividend == 0) return 0;
    bool negative = false;
    if ((dividend > 0 && divisor < 0) || (dividend < 0 && divisor > 0))
      negative = true;
    dividend = dividend > 0 ? -dividend : dividend;
    divisor = divisor > 0 ? -divisor : divisor;
    std::deque<int> divisors{divisor};
    while (dividend - divisors.front() <= divisors.front())
      divisors.push_front(divisors.front() + divisors.front());
    int ans = 0;
    for (const auto& subtrahend : divisors) {
      ans *= 2;
      if (dividend - subtrahend <= 0) {
        dividend -= subtrahend;
        --ans;
      }
    }
    if (!negative && ans < -std::numeric_limits<int>::max())
      return std::numeric_limits<int>::max();
    return negative ? ans : -ans;
  }
};
