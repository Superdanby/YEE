#include <bits/stdc++.h>

using namespace std;

constexpr int degree_max = 360;

int main(int argc, char const *argv[]) {
    int nums, inp;
    cin >> nums;
    unordered_set<int> degree, prev({0});
    for (int i = 0; i < nums; ++i)
    {
        cin >> inp;
        for (auto x: prev)
        {
            degree.insert(x + inp);
            degree.insert(x - inp);
        }
        prev.clear();
        prev.swap(degree);
    }
    for (auto x: prev)
    {
        if (x % degree_max == 0)
        {
            cout << "YES\n";
            return 0;
        }
    }
    cout << "NO\n";
    return 0;
}
