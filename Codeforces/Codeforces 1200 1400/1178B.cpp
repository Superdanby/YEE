#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    string inp;
    cin >> inp;
    vector<ll> left(inp.length(), 0), right(inp.length(), 0);
    for (size_t i = 2, j = inp.length() - 3; i < inp.length(); ++i, --j)
    {
        if (inp[i - 1] == 'v' && inp[i - 2] == 'v')
            left[i] = left[i - 1] + 1;
        else
            left[i] = left[i - 1];
        if (inp[j + 1] == 'v' && inp[j + 2] == 'v')
            right[j] = right[j + 1] + 1;
        else
            right[j] = right[j + 1];
    }
    ll ans = 0;
    for (size_t i = 0; i < inp.length(); ++i)
        if (inp[i] =='o')
            ans += left[i] * right[i];
    cout << ans << "\n";

    return 0;
}
