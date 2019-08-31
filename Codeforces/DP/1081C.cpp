#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
constexpr ll MAX = 998244353;

int main(int argc, char const *argv[]) {
    int size, colors, cuts;
    cin >> size >> colors >> cuts;
    vector<ll> cnt(size), prev(size, colors--);
    for (int i = 0; i < cuts; ++i)
    {
        for (int j = i + 1; j < size - cuts + i + 1; ++j)
        {
            cnt[j] = (cnt[j - 1] + colors * prev[j - 1]) % MAX;
        }
        prev.swap(cnt);
        cnt[i + 1] = 0;
    }
    cout << prev.back() << "\n";
    return 0;
}
