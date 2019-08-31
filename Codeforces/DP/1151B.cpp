#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int rows, columns;
    cin >> rows >> columns;
    vector<unordered_map<int, int>> dict(rows, unordered_map<int, int>());
    int inp, value = 0;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 1; j <= columns; ++j)
        {
            cin >> inp;
            if (dict[i].find(inp) == dict[i].end())
                dict[i][inp] = j;
        }
        value ^= dict[i].begin()->first;
    }
    if (value)
    {
        cout << "TAK\n" << dict[0].begin()->second;
        for (int i = 1; i < rows; ++i)
            cout << " " << dict[i].begin()->second;
        cout << "\n";
        return 0;
    }
    bool yes = false;
    for (auto && x: dict)
        if (x.size() > 1)
        {
            auto y = x.begin();
            ++y;
            x.begin()->second = y->second;
            yes = true;
            break;
        }
    if (yes)
    {
        cout << "TAK\n" << dict[0].begin()->second;
        for (int i = 1; i < rows; ++i)
            cout << " " << dict[i].begin()->second;
        cout << "\n";
        return 0;
    }
    cout << "NIE\n";

    return 0;
}
