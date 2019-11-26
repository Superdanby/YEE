#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    unordered_map<int, vector<int>> dict;
    int inp;
    for (int i = 0; i < nums; ++i)
    {
        cin >> inp;
        dict[inp].push_back(i);
    }
    int one = 0, many = 0;
    for (auto [value, indices]: dict)
    {
        if (indices.size() == 1)
            ++one;
        else if (indices.size() > 2)
            ++many;
    }
    vector<char> ans(nums);
    int control = 0;
    if ((one & 1) && !many)
    {
        cout << "NO\n";
        return 0;
    }
    else if (one & 1)
    {
        bool balance = true;
        for (auto [value, indices]: dict)
        {
            if (indices.size() == 1)
            {
                if (++control & 1)
                    ans[indices.front()] = 'A';
                else
                    ans[indices.front()] = 'B';
            }
            else if (indices.size() > 2 && balance)
            {
                balance = false;
                ans[indices.front()] = 'B';
                for (auto it = indices.begin() + 1; it != indices.end(); ++it)
                    ans[*it] = 'A';
            }
            else
                for (auto idx: indices)
                    ans[idx] = 'A';
        }
    }
    else
    {
        for (auto [value, indices]: dict)
        {
            if (indices.size() == 1)
            {
                if (++control & 1)
                    ans[indices.front()] = 'A';
                else
                    ans[indices.front()] = 'B';
            }
            else
                for (auto idx: indices)
                    ans[idx] = 'A';
        }
    }
    cout << "YES\n";
    for (auto x: ans)
        cout << x;
    cout << "\n";
    return 0;
}
