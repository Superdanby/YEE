class Solution {
 public:
  int strStr(string haystack, string needle) {
    std::vector<int> kmp(needle.length());
    for (int idx = 1, jump = 0; idx < needle.length(); ++idx) {
      while (jump && needle.at(jump) != needle.at(idx)) jump = kmp.at(jump - 1);
      if (needle.at(jump) == needle.at(idx)) ++jump;
      kmp.at(idx) = jump;
      //     a  b  a  b  c  a  b  a  b  b
      //     0  0  1  2  0  1  2  3  4  0
      // a b a a c
      // 0 0 1 1
    }
    for (int idx = 0, kdx = 0; idx < haystack.length(); ++idx) {
      while (kdx && haystack.at(idx) != needle.at(kdx)) kdx = kmp.at(kdx - 1);
      if (haystack.at(idx) == needle.at(kdx)) ++kdx;
      if (kdx == kmp.size()) return idx - kdx + 1;
    }
    return -1;
  }
};
