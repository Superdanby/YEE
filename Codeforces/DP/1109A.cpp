#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    // vector<int> num(nums);
    // for (auto && x: num)
    //     cin >> x;
    // vector<int> xor_val(num);
    // int ans = 0;
    // for (size_t i = 1; 2 * i <= num.size(); ++i)
    // {
    //     for (size_t j = 0; j + i < num.size(); ++j)
    //     {
    //         if (j + i < xor_val.size() && xor_val[j] == xor_val[j + i])
    //             ++ans;
    //         xor_val[j] ^= num[j + i];
    //     }
    //     xor_val.pop_back();
    // }
    unordered_map<int, int> odd{{0, 1}}, even;
    int value = 0, inp;
    long long ans = 0;
    for (int i = 0; i < nums; ++i)
    {
        cin >> inp;
        value ^= inp;
        if (i & 1)
        {
            if (odd.find(value) == odd.end())
                odd[value] = 1;
            else
            {
                ans += odd[value];
                ++odd[value];
            }
        }
        else
        {
            if (even.find(value) == even.end())
                even[value] = 1;
            else
            {
                ans += even[value];
                ++even[value];
            }
        }
    }
    cout << ans << "\n";
    return 0;
}
