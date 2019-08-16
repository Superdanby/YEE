#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    int w, h;
    cin >> w >> h;
    ll ans = 1;
    w += h;
    while (w--)
    {
        ans <<= 1;
        ans %= 998244353;
    }
    cout << ans << "\n";
    return 0;
}
