class Solution {
 public:
  bool isPalindrome(int x) {
    if (x < 0) return false;
    int64_t reverse = 0, duplicate = x;
    while (x) {
      reverse *= 10;
      reverse += x % 10;
      x /= 10;
    }
    return reverse == duplicate;
  }
};