#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        string source, target, ingredients;
        cin >> source >> target >> ingredients;
        auto target_it = target.begin();
        vector<int> cnt(26, 0);
        int i = 0;
        for (int j = 0; i < source.size() && j < target.size(); ++i, ++j)
        {
            while (j < target.size() && source[i] != target[j])
                ++j;
            if (j == target.size())
                break;
            ++cnt[source[i] - 'a'];
        }
        if (i != source.size())
        {
            cout << "NO\n";
            continue;
        }
        for (auto x: ingredients)
            ++cnt[x - 'a'];
        i = 0;
        for (; i < target.size(); ++i)
        {
            if (--cnt[target[i] - 'a'] < 0)
            {
                cout << "NO\n";
                break;
            }
        }
        if (i == target.size())
            cout << "YES\n";
    }
    return 0;
}
