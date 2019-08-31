#include <bits/stdc++.h>

using namespace std;

constexpr long long MAX = 1e9 + 7;

int main(int argc, char const *argv[]) {
    int size, lb, ub;
    cin >> size >> lb >> ub;
    vector<long long> base(3, (ub += -lb + 1) / 3);
    for (int i = 0, j = ub % 3; j > 0; ++i, --j)
        ++base[(i + lb) % 3];
    vector<long long> cnt(3, -1), prev(base);
    for (int i = 1; i < size; ++i)
    {
        cnt[0] = (prev[0] * base[0]) % MAX + (prev[1] * base[2]) % MAX + (prev[2] * base[1]) % MAX;
        cnt[1] = (prev[0] * base[1]) % MAX + (prev[1] * base[0]) % MAX + (prev[2] * base[2]) % MAX;
        cnt[2] = (prev[0] * base[2]) % MAX + (prev[2] * base[0]) % MAX + (prev[1] * base[1]) % MAX;
        prev.swap(cnt);
    }
    cout << prev[0] % MAX << "\n";

    return 0;
}
