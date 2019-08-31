#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    unordered_map<int, pair<int, int>> dict;
    vector<int> base{4, 8, 15, 16, 23, 42};
    for (int i = 0; i < 5; ++i)
        for (int j = i + 1; j < 6; ++j)
            dict[base[i] * base[j]] = pair<int, int>(base[i], base[j]);
    int inp, prev;
    vector<int> ans(6, 0);
    cout << "? 1 2\n";
    fflush(stdout);
    cin >> prev;
    cout << "? 2 3\n";
    fflush(stdout);
    cin >> inp;
    int last = 4 + 8 + 15 + 16 + 23 + 42;
    pair<int, int> fir = dict[prev], sec = dict[inp];
    if (fir.first == sec.first)
        ans[0] = fir.second, ans[1] = fir.first , ans[2] = sec.second;
    else if (fir.first == sec.second)
        ans[0] = fir.second, ans[1] = fir.first , ans[2] = sec.first;
    else if (fir.second == sec.first)
        ans[0] = fir.first, ans[1] = fir.second , ans[2] = sec.second;
    else
        ans[0] = fir.first, ans[1] = fir.second , ans[2] = sec.first;
    cout << "? 3 4\n";
    fflush(stdout);
    cin >> inp;
    ans[3] = inp / ans[2];
    cout << "? 4 5\n";
    fflush(stdout);
    cin >> inp;
    ans[4] = inp / ans[3];
    cout << "! ";
    for (int i = 0; i < 5; ++i)
    {
        last -= ans[i];
        cout << ans[i] << " ";
    }
    cout << last << "\n";
    return 0;
}
