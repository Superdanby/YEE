class Solution {
 public:
  string convert(string s, int numRows) {
    if (numRows == 1) return s;
    std::vector<std::string> order(numRows);
    int direction = -1, row = 0;
    for (const auto& value : s) {
      order.at(row).append(1, value);
      if (row == 0 || row == numRows - 1) direction *= -1;
      row += direction;
    }
    std::string ans;
    for (const auto ordered : order) ans.append(std::move(ordered));
    return ans;
  }
};
