#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cnt;
    int parts;
    cin >> cnt >> parts;
    vector<int> inp(cnt);
    for(auto & x: inp)
        cin >> x;
    vector<pair<int, int>> diff(cnt - 1);
    auto it = inp.begin();
    auto prev = it++;
    auto diff_it = diff.begin();
    for(;it != inp.end(); ++it, ++prev, ++diff_it)
    {
        diff_it -> first = *it - *prev;
        diff_it -> second = it - inp.begin() - 1;
    }
    sort(diff.begin(), diff.end(), greater<decltype(diff.front())>());
    sort(diff.begin(), diff.begin() + parts - 1, [](auto & A, auto & B) {return A.second < B.second;});
    int idx = 0, sum = 0;
    for (int i = 0; i < parts - 1; ++i)
    {
        // cout << diff[i].first << " " << diff[i].second << "\n";
        auto x = diff[i].second;
        sum += inp[x] - inp[idx];
        idx = x + 1;
    }
    sum += inp.back() - inp[idx];
    cout << sum << "\n";

    return 0;
}
