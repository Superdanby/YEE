class Solution {
 public:
  bool isValidSudoku(vector<vector<char>>& board) {
    return ValidateRows(board) && ValidateColumns(board) &&
           ValidateGrids(board);
  }
  bool ValidateRows(vector<vector<char>>& board) {
    std::unordered_set<char> insert_once;
    insert_once.reserve(9);
    for (int i = 0; i < board.size(); ++i) {
      for (int j = 0; j < board.at(i).size(); ++j) {
        if (board.at(i).at(j) == '.') continue;
        auto [_, success] = insert_once.insert(board.at(i).at(j));
        if (!success) return false;
      }
      insert_once.clear();
    }
    return true;
  }
  bool ValidateColumns(vector<vector<char>>& board) {
    std::unordered_set<char> insert_once;
    insert_once.reserve(9);
    for (int j = 0; j < board.size(); ++j) {
      for (int i = 0; i < board.at(j).size(); ++i) {
        if (board.at(i).at(j) == '.') continue;
        auto [_, success] = insert_once.insert(board.at(i).at(j));
        if (!success) return false;
      }
      insert_once.clear();
    }
    return true;
  }
  bool ValidateGrids(vector<vector<char>>& board) {
    std::unordered_set<char> insert_once;
    insert_once.reserve(9);
    for (int i = 0; i < board.size(); i += 3) {
      for (int j = 0; j < board.at(i).size(); j += 3) {
        for (int idx = 0; idx < 3; ++idx) {
          for (int jdx = 0; jdx < 3; ++jdx) {
            if (board.at(i + idx).at(j + jdx) == '.') continue;
            auto [_, success] =
                insert_once.insert(board.at(i + idx).at(j + jdx));
            if (!success) return false;
          }
        }
        insert_once.clear();
      }
    }
    return true;
  }
};