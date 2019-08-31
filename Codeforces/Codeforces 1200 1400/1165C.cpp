#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int length;
    cin >> length;
    string inp;
    cin >> inp;
    string ans(inp.begin(), inp.begin() + 1);
    for (int i = 0, j = 1; j < length; ++j)
    {
        if (ans.length() & 1)
            while (j < length && inp[i] == inp[j])
                ++j;
        if (j < length)
            ans += inp[j];
        i = j;
    }
    if (ans.length() & 1)
        ans.pop_back();
    cout << inp.length() - ans.length() << "\n" << ans << "\n";
    return 0;
}
