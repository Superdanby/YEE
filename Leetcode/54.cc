class Solution {
 public:
  vector<int> spiralOrder(vector<vector<int>>& matrix) {
    std::vector<int> ans{matrix.front().front()};
    std::vector<int> direction{1, 1, -1, -1};
    std::vector<int> limit{int(matrix.front().size()), int(matrix.size()), -1,
                           0};
    std::vector<int> position{0, 0};
    int advance = -1, axis = 0, cnt = 1;
    while (cnt < matrix.size() * matrix.front().size()) {
      advance = (advance + 1) % 4;
      axis = (axis + 1) % 2;
      while (position.at(axis) + direction.at(advance) != limit.at(advance)) {
        position.at(axis) += direction.at(advance);
        ans.push_back(matrix.at(position.front()).at(position.back()));
        ++cnt;
      }
      if (advance < 2)
        --limit.at(advance);
      else
        ++limit.at(advance);
    }
    return ans;
  }
};
