#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

ll MAX = 1e9 + 7;

int main(int argc, char const *argv[]) {
    char inp;
    vector<ll> as(1, 0);
    while (cin >> inp)
    {
        if (as.back() == 0 && inp == 'b')
            continue;
        else if (inp == 'b')
            as.push_back(0);
        else if (inp == 'a')
            ++as.back();
    }
    ll ans = as.front() + 1;
    for (auto it = as.begin() + 1; it != as.end(); ++it)
    {
        ans *= (*it + 1);
        ans %= MAX;
    }
    cout << --ans << "\n";
    return 0;
}
