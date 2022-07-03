class Solution {
 public:
  void solveSudoku(vector<vector<char>>& board) {
    std::vector<int> rows = RowCandidates(board),
                     columns = ColumnCandidates(board),
                     grids = GridCandidates(board);
    Fit(board, rows, columns, grids, 0, 0);
  }
  bool Fit(std::vector<std::vector<char>>& board, std::vector<int>& rows,
           std::vector<int>& columns, std::vector<int>& grids, int i, int j) {
    if (i == 9) return true;
    int next_i, next_j;
    if (j < 8)
      next_i = i, next_j = j + 1;
    else
      next_i = i + 1, next_j = 0;
    if (board.at(i).at(j) != '.')
      return Fit(board, rows, columns, grids, next_i, next_j);
    for (int num = 1, candidates = rows.at(i) | columns.at(j) |
                                   grids.at(i / 3 * 3 + j / 3);
         num < 10; ++num) {
      int candidate = (1 << num);
      //   std::cout << std::bitset<16>(candidate) << " "
      //             << std::bitset<16>(rows.at(i)) << " "
      //             << std::bitset<16>(columns.at(j)) << " "
      //             << std::bitset<16>(grids.at(i / 3 * 3 + j / 3)) << "\n";
      if (candidate & candidates) continue;
      rows.at(i) += candidate;
      columns.at(j) += candidate;
      grids.at(i / 3 * 3 + j / 3) += candidate;
      board.at(i).at(j) = num + '0';
      if (Fit(board, rows, columns, grids, next_i, next_j)) return true;
      board.at(i).at(j) = '.';
      rows.at(i) -= candidate;
      columns.at(j) -= candidate;
      grids.at(i / 3 * 3 + j / 3) -= candidate;
    }
    return false;
  }
  std::vector<int> RowCandidates(vector<vector<char>>& board) {
    std::vector<int> rows(9, 0);
    for (int i = 0; i < board.size(); ++i)
      for (int j = 0; j < board.at(i).size(); ++j)
        if (board.at(i).at(j) != '.')
          rows.at(i) += (1 << (board.at(i).at(j) - '0'));
    return rows;
  }
  std::vector<int> ColumnCandidates(vector<vector<char>>& board) {
    std::vector<int> columns(9, 0);
    for (int j = 0; j < board.size(); ++j)
      for (int i = 0; i < board.at(j).size(); ++i)
        if (board.at(i).at(j) != '.')
          columns.at(j) += (1 << (board.at(i).at(j) - '0'));
    return columns;
  }
  std::vector<int> GridCandidates(vector<vector<char>>& board) {
    std::vector<int> grids(9, 0);
    for (int i = 0; i < board.size(); i += 3)
      for (int j = 0; j < board.at(i).size(); j += 3)
        for (int idx = 0; idx < 3; ++idx)
          for (int jdx = 0; jdx < 3; ++jdx)
            if (board.at(i + idx).at(j + jdx) != '.')
              grids.at(i + j / 3) +=
                  (1 << (board.at(i + idx).at(j + jdx) - '0'));
    return grids;
  }
};