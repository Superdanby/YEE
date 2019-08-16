#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    ll inp;
    cin >> inp;
    for (ll i = 1; i * i <= inp; ++i)
    {
        ll y = (inp - i * i - i - 1) / 2 / i;
        if (inp == i * i + 2 * y * i + i + 1 && y > 0)
        {
            cout << i << " " << y << "\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
