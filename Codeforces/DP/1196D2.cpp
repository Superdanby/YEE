#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        int length, target;
        cin >> length >> target;
        vector<vector<int>> BGR(3, vector<int>(length, 0));
        string inp;
        cin >> inp;
        for (size_t i = 0, tok; i < inp.length(); ++i)
        {
            if (inp[i] == 'B')
                tok = 0;
            else if (inp[i] == 'G')
                tok = 1;
            else
                tok = 2;
            BGR[(tok + i) % 3][i] = 1;
        }
        int ans = target;
        for (auto x: BGR)
        {
            size_t j = 0;
            int init = target;
            for (; j < target; ++j)
                init -= x[j];
            ans = init < ans ? init : ans;
            for (size_t i = 0; j < x.size(); ++i, ++j)
            {
                init += x[i] - x[j];
                ans = init < ans ? init : ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
