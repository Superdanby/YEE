#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        ll charge, turns, a, b;
        cin >> charge >> turns >> a >> b;
        ll base = charge - turns * b - 1;
        if (base >= 0)
        {
            ll add_rate = a - b;
            cout << min(turns, base / add_rate) << "\n";
        }
        else
            cout << "-1\n";
    }
    return 0;
}
