#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    string inp;
    cin >> inp;
    int num[inp.size()];
    for (int i = 0; i < inp.length(); ++i)
    {
        num[i] = inp[i] - '0';
    }
    int dp[inp.size() + 1];
    fill(dp, dp + inp.size() + 1, 0);
    dp[1] = num[0] % 3 == 0;
    for (size_t i = 0; i < inp.size(); ++i)
    {
        if (i > 1 && num[i - 2])
            dp[i + 1] = max(dp[i + 1], dp[i - 3 + 1] + ((num[i - 2] + num[i - 1] + num[i]) % 3 == 0 ? 1 : 0));
        if (i > 0 && num[i - 1])
            dp[i + 1] = max(dp[i + 1], dp[i - 2 + 1] + ((num[i - 1] + num[i]) % 3 == 0 ? 1 : 0));
        dp[i + 1] = max(dp[i + 1], dp[i - 1 + 1] + ((num[i]) % 3 == 0 ? 1 : 0));
        // for (auto x: dp)
        //     cout << x << " ";
        // cout << "\n";
    }
    cout << dp[inp.size()] << "\n";
    return 0;
}
