#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int ub;
    cin >> ub;
    vector<int> value(ub + 1, 0);
    for (int i = 2, cnt = 0; i <= ub; ++i)
    {
        if (value[i])
            continue;
        ++cnt;
        for (int j = i; j <= ub; j += i)
        {
            if (!value[j])
                value[j] = cnt;
        }
    }
    auto end = value.end() - 1;
    for (auto it = value.begin() + 2; it != end; ++it)
        cout << *it << " ";
    cout << *end << "\n";
    return 0;
}
