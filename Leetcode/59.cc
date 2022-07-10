class Solution {
 public:
  vector<vector<int>> generateMatrix(int n) {
    std::vector<std::vector<int>> ans(n, std::vector<int>(n));
    int val = 0;
    std::vector<int> advance{1, 1, -1, -1}, position{0, -1}, limit{n, n, -1, 0};
    int direction = 0, axis = 1;
    while (val < n * n) {
      if (position.at(axis) + advance.at(direction) == limit.at(direction)) {
        if (direction < 2)
          --limit.at(direction);
        else
          ++limit.at(direction);
        direction = (direction + 1) % 4, axis = (axis + 1) % 2;
      }
      position.at(axis) += advance.at(direction);
      ans.at(position.front()).at(position.back()) = ++val;
    }
    return ans;
  }
};
