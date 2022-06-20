class Solution {
 public:
  bool isValid(string s) {
    std::stack<char> pairing;
    for (const auto &parentheses : s)
      if (!pairing.empty() && (pairing.top() == '(' && parentheses == ')' ||
                               pairing.top() == '[' && parentheses == ']' ||
                               pairing.top() == '{' && parentheses == '}'))
        pairing.pop();
      else
        pairing.push(parentheses);
    return pairing.empty();
  }
};