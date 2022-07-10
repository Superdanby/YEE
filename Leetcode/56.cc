class Solution {
 public:
  vector<vector<int>> merge(vector<vector<int>>& intervals) {
    std::sort(intervals.begin(), intervals.end());
    std::vector<std::vector<int>> ans{
        {intervals.front().front(), intervals.front().back()}};
    for (const auto& interval : intervals) {
      if (ans.back().back() < interval.front())
        ans.push_back({interval.front(), interval.back()});
      else
        ans.back().back() = interval.back() > ans.back().back()
                                ? interval.back()
                                : ans.back().back();
    }
    return ans;
  }
};
