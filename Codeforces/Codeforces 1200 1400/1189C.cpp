#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    int nums;
    cin >> nums;
    vector<int> sums(nums + 1);
    sums.front() = 0;
    for (auto it = sums.begin() + 1; it != sums.end(); ++it)
    {
        cin >> *it;
        *it += *(it - 1);
    }
    int queries;
    cin >> queries;
    int lb, ub;
    while (queries--)
    {
        cin >> lb >> ub;
        cout << (sums[ub] - sums[lb - 1]) / 10 << "\n";
    }

    return 0;
}
