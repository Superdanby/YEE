class Solution {
 public:
  vector<int> findSubstring(string s, vector<string>& words) {
    int word_length = words.front().length();
    std::map<std::string, int> origin;
    for (const auto& word : words) {
      auto [it, success] = origin.insert({word, 0});
      ++it->second;
    }
    std::vector<int> ans;
    for (int shift = 0; shift < word_length; ++shift) {
      std::map<std::string, int> dict = origin;
      for (int idx = shift, front = shift; idx < s.length();
           idx += word_length) {
        auto it = dict.find(s.substr(idx, word_length));
        if (it == dict.end()) {
          while (front != idx) Pop(s, dict, front, word_length);
          front += word_length;
        } else if (it->second == 0) {
          while (s.substr(front, word_length) != it->first)
            Pop(s, dict, front, word_length);
          front += word_length;
        } else {
          --it->second;
          if (idx - front + word_length == word_length * words.size()) {
            ans.push_back(front);
            Pop(s, dict, front, word_length);
          }
        }
      }
    }
    return ans;
  }

  void Pop(std::string& s, std::map<std::string, int>& dict, int& idx,
           int word_length) {
    auto it = dict.find(s.substr(idx, word_length));
    if (it != dict.end()) ++it->second;
    idx += word_length;
  }
};
