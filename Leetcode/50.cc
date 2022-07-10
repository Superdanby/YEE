class Solution {
 public:
  double myPow(double x, int n) {
    int64_t ub = n;
    if (ub < 0) x = 1 / x, ub = -ub;
    std::vector<double> values{1, x};
    int64_t pow = 1;
    for (; pow < ub; pow *= 2) {
      values.push_back(values.back() * values.back());
    }
    double ans = 1;
    for (auto it = values.rbegin(); ub > 0; ++it, pow /= 2)
      if (ub >= pow) ub -= pow, ans *= *it;
    return ans;
  }
};
