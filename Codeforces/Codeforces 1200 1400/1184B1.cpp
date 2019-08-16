#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int ships, bases;
    cin >> ships >> bases;
    vector<int> ship(ships);
    vector<pair<int, int>> base;
    for (auto &x: ship)
        cin >> x;
    int power, gold;
    for (int i = 0; i < bases; ++i)
    {
        cin >> power >> gold;
        base.push_back(make_pair(power, gold));
    }
    sort(base.begin(), base.end());
    auto it = base.begin(), previt = base.begin();
    for (++it; it != base.end(); ++it, ++previt)
        it->second += previt->second;
    vector<int> ans;
    for (auto x: ship)
    {
        // auto pos = lower_bound(base.begin(), base.end(), make_pair(x + 1, 0));
        // if (pos == base.begin() || x < (--pos)->first)
        //     ans.push_back(0);
        // else
        //     ans.push_back(pos->second);
        int lb = 0, ub = base.size(), pivot;
        while (ub - lb > 1)
        {
            pivot = (ub + lb) / 2;
            if (base[pivot].first > x)
                ub = pivot;
            else
                lb = pivot;
        }
        if (base[lb].first > x)
            ans.push_back(0);
        else
            ans.push_back(base[lb].second);
    }
    auto ansit = ans.begin();
    auto endit = ans.end();
    --endit;
    for (; ansit != endit; ++ansit)
    {
        cout << *ansit << " ";
    }
    cout << *endit << "\n";
    return 0;
}
