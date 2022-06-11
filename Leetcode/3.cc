class Solution {
 public:
  int lengthOfLongestSubstring(string s) {
    unordered_set<char> cache;
    int left = -1, right = -1, ans = 0;
    while (++right < s.size()) {
      while (cache.find(s.at(right)) != cache.end()) cache.erase(s.at(++left));
      cache.insert(s.at(right));
      ans = cache.size() > ans ? cache.size() : ans;
    }
    return ans;
  }
};
