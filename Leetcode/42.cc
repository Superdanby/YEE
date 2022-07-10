class Solution {
 public:
  int trap(vector<int>& height) {
    int left = 0, roof = 0, ans = 0, local = 0;
    for (int i = 0; i < height.size(); ++i) {
      if (height.at(i) < roof)
        local += roof - height.at(i);
      else {
        ans += local;
        local = 0;
        roof = height.at(i);
        left = i;
      }
    }
    roof = 0, local = 0;
    for (int i = height.size() - 1; i >= left; --i) {
      if (height.at(i) < roof)
        local += roof - height.at(i);
      else {
        ans += local;
        local = 0;
        roof = height.at(i);
      }
    }
    return ans;
  }
};
