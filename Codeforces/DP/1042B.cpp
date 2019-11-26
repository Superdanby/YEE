#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int strings;
    cin >> strings;
    vector<int> mins(8, 1e7);
    while (strings--)
    {
        int value;
        string inp;
        int MASK = 0;
        cin >> value >> inp;
        for (auto x: inp)
        {
            if (x == 'A')
                MASK |= 1;
            else if (x == 'B')
                MASK |= 2;
            else if (x == 'C')
                MASK |= 4;
        }
        mins[MASK] = mins[MASK] < value ? mins[MASK] : value;
        // for (auto x: mins)
        //     cout << x << " ";
        // cout << '\n';

    }
    int ans = min(mins[1] + mins[2] + mins[4], min(mins[1] + mins[6], min(mins[2] + mins[5], min(mins[4] + mins[3], min(mins[7], min(mins[3] + mins[5], min(mins[3] + mins[6], mins[5] + mins[6])))))));
    if (ans >= mins[0])
        cout << "-1\n";
    else
        cout << ans << "\n";
    return 0;
}
