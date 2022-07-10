class Solution {
 public:
  int totalNQueens(int n) {
    int mask = 0;
    for (int i = 0; i < n; ++i) mask = mask * 2 + 1;
    std::vector<int> board(n, mask);
    int ans = 0;
    dfs(board, 0, ans);
    return ans;
  }
  void dfs(std::vector<int> &board, int row, int &ans) {
    if (row == board.size()) {
      ++ans;
      return;
    }
    for (int mask = 1; mask <= board.at(row); mask *= 2) {
      if (board.at(row) & mask) {
        auto new_board = board;
        for (int j = row; j < new_board.size(); ++j) new_board.at(j) &= ~mask;
        for (int j = row, mask_ = mask;
             j < new_board.size() && mask_ <= (1 << board.size());
             ++j, mask_ *= 2)
          new_board.at(j) &= ~mask_;
        for (int j = row, mask_ = mask; j < new_board.size() && mask >= 0;
             ++j, mask_ /= 2)
          new_board.at(j) &= ~mask_;
        dfs(new_board, row + 1, ans);
      }
    }
  }
};
