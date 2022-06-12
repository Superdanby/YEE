class Solution {
 public:
  int maxArea(vector<int>& height) {
    std::deque<std::pair<int, int>> dsce, asce;
    int highest = 0;
    for (int i = 0; i < height.size(); ++i)
      if (height.at(i) > highest) {
        highest = height.at(i);
        asce.push_back({highest, i});
      }
    highest = 0;
    for (int i = height.size() - 1; i >= 0; --i)
      if (height.at(i) > highest) {
        highest = height.at(i);
        dsce.push_front({highest, i});
      }

    auto ait = asce.begin();
    auto dit = dsce.rbegin();
    int ans = 0;
    while (dit != dsce.rend() && ait != asce.end() &&
           dit->second > ait->second) {
      int area = (dit->first > ait->first ? ait->first : dit->first) *
                 (dit->second - ait->second);
      ans = area > ans ? area : ans;
      if (ait->first < dit->first)
        ++ait;
      else
        ++dit;
    }
    return ans;
  }
};