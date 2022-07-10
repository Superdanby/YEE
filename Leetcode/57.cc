class Solution {
 public:
  vector<vector<int>> insert(vector<vector<int>>& intervals,
                             vector<int>& newInterval) {
    auto it = std::lower_bound(
        intervals.begin(), intervals.end(),
        std::vector<int>{newInterval.front(), newInterval.front()});
    if (it != intervals.end() && it->front() == newInterval.front() &&
        it->back() >= newInterval.back())
      return intervals;
    if (it != intervals.begin()) {
      --it;
      if (it->back() >= newInterval.front())
        newInterval.front() = it->front();
      else
        ++it;
    }
    auto next_it = it;
    while (next_it != intervals.end() && next_it->front() <= newInterval.back())
      ++next_it;
    if (next_it != intervals.begin()) {
      newInterval.back() = (--next_it)->back() > newInterval.back()
                               ? next_it->back()
                               : newInterval.back();
      ++next_it;
    }
    std::vector<std::vector<int>> ans(intervals.begin(), it);
    ans.push_back(newInterval);
    if (next_it == intervals.end()) return ans;
    ans.insert(ans.end(), next_it, intervals.end());
    return ans;
  }
};
