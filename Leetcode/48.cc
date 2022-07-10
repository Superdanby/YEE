class Solution {
 public:
  void rotate(vector<vector<int>>& matrix) {
    std::vector<std::pair<int, int>> directions{
        {1, 1}, {1, -1}, {-1, -1}, {-1, 1}};
    int front = 0, end = matrix.size() - 1;
    while (front < end) {
      for (int i = front; i < end; ++i) {
        int idx = front, jdx = i;
        int prev = matrix.at(idx).at(jdx);
        int len_1 = i - front, len_2 = end - i;
        for (const auto& [x, y] : directions) {
          idx += len_1 * x, jdx += len_2 * y;
          swap(len_1, len_2);
          swap(prev, matrix.at(idx).at(jdx));
        }
      }
      ++front, --end;
    }
  }
};
