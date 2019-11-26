#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int range, wings;
    cin >> range >> wings;
    int cnt = (range - 1) / (2 * wings + 1) + 1;
    cout << cnt << "\n";
    // int start = range - (1 + (2 * wings + 1) * cnt);
    // start = 0 > start ? 0 : start;
    int start = (2 * wings + 1) * cnt - wings;
    if (start > range)
        start = range;
    cout << start;
    start -= (2 * wings + 1);
    while (start > 0)
    {
        cout << " " << start;
        start -= (2 * wings + 1);
    }
    cout << "\n";
    return 0;
}
