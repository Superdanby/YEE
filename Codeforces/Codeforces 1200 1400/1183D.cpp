#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        int nums;
        cin >> nums;
        unordered_map<int, int> dict;
        int inp;
        for (int i = 0; i < nums; ++i)
        {
            cin >> inp;
            if (dict.find(inp) == dict.end())
                dict[inp] = 1;
            else
                ++dict[inp];
        }
        priority_queue<int> cnt;
        for (auto x: dict)
            cnt.push(x.second);
        int ans = cnt.top();
        cnt.pop();
        int bound = ans;
        while(!cnt.empty() && bound)
        {
            int val = cnt.top();
            cnt.pop();
            val = val < bound ? val : bound - 1;
            ans += val;
            bound = val;
        }
        cout << ans << "\n";
    }
    return 0;
}
