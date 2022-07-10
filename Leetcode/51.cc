class Solution {
 public:
  vector<vector<string>> solveNQueens(int n) {
    std::vector<std::vector<bool>> board(n, std::vector<bool>(n));
    std::vector<std::vector<std::string>> ans;
    std::vector<int> empty;
    dfs(board, 0, empty, ans);
    return ans;
  }
  void dfs(std::vector<std::vector<bool>> &board, int row,
           std::vector<int> &idx, std::vector<std::vector<std::string>> &ans) {
    if (row == board.size()) {
      ans.emplace_back(std::vector(row, std::string(row, '.')));
      for (int i = 0; i < row; ++i) ans.back().at(i).at(idx.at(i)) = 'Q';
      return;
    }
    for (int i = 0; i < board.size(); ++i) {
      if (!board.at(row).at(i)) {
        idx.push_back(i);
        auto new_board = board;
        for (int j = row; j < new_board.size(); ++j)
          new_board.at(j).at(i) = true;
        for (int j = row, k = i; j < new_board.size() && k < new_board.size();
             ++j, ++k)
          new_board.at(j).at(k) = true;
        for (int j = row, k = i; j < new_board.size() && k >= 0; ++j, --k)
          new_board.at(j).at(k) = true;
        dfs(new_board, row + 1, idx, ans);
        idx.pop_back();
      }
    }
  }
};
