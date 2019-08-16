#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    map<int, queue<int>> cnt{{4, queue<int>()}, {8, queue<int>()}, {15, queue<int>()}, {16, queue<int>()}, {23, queue<int>()}, {42, queue<int>()}};
    int nums;
    cin >> nums;
    int inp;
    for (int i = 0; i < nums; ++i)
    {
        cin >> inp;
        cnt[inp].push(i);
    }
    int ans = 0;
    while (cnt.begin()->second.size())
    {
        auto next = cnt.begin(), prev = cnt.begin();
        ++next;
        for (; next != cnt.end(); ++next, ++prev)
        {
            while (next->second.size() && next->second.front() < prev->second.front())
            {
                ++ans;
                next->second.pop();
            }
            if (!next->second.size())
                break;
        }
        if (next != cnt.end())
            break;
        for (; prev != cnt.begin(); --prev)
            prev->second.pop();
        prev->second.pop();
    }
    for (auto x: cnt)
        ans += x.second.size();
    cout << ans << "\n";
    return 0;
}
