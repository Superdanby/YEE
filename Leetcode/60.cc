class Solution {
 public:
  string getPermutation(int n, int k) {
    std::string ans = "";
    for (int i = 1; i <= n; ++i) ans.push_back('0' + i);
    while (k > 1) {
      int digit = 0, ub = 1;
      while (ub < k) ub *= (++digit + 1);
      ub /= (digit + 1);
      int new_lead = digit - (k + ub - 1) / ub + 1;
      k -= (k - 1) / ub * ub;
      char prev = ans.at(ans.length() - new_lead - 1);
      for (int i = ans.length() - digit - 1; i < ans.length() - new_lead; ++i)
        swap(prev, ans.at(i));
    }
    return ans;
  }
};

// digit ub
// 0 1
// 1 2
// 2 6
// 3 24

// ans k
// 123 1
// 132 2
// 213 3
// 231 4
// 312 5
// 321 6
