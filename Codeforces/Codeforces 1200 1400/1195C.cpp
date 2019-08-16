#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int main(int argc, char const *argv[]) {
    int columns;
    cin >> columns;
    vector<vector<ll>> dp (2, vector<ll>(columns + 1));
    for (int i = 0; i < 2; ++i)
        for (int j = 1; j < columns + 1; ++j)
            cin >> dp[i][j];
    for (int i = 2; i < columns + 1; ++i)
        for (int j = 0; j < 2; ++j)
        {
            dp[j][i] += max(dp[1 - j][i - 2], dp[1 - j][i - 1]);
        }
    cout << max(dp[0][columns], dp[1][columns]) << "\n";
    return 0;
}
