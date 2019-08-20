#include <bits/stdc++.h>

using namespace std;
using uf_type = vector<pair<int, int>>;

int parent(uf_type &union_find, int child)
{
    if (union_find[child].first == -1 || union_find[child].first == child)
        return union_find[child].first = child;
    int new_parent = parent(union_find, union_find[child].first);
    union_find[child].first = new_parent;
    union_find[new_parent].second += union_find[child].second;
    union_find[child].second = 0;
    return new_parent;
}

int main(int argc, char const *argv[]) {
    int people, groups;
    cin >> people >> groups;
    uf_type union_find(people, pair<int, int>(-1, 1));
    while (groups--)
    {
        int connections, inp;
        cin >> connections;
        if (!connections)
            continue;
        --connections;
        cin >> inp;
        int parentx = parent(union_find, inp - 1), parenty;
        for (int i = 0; i < connections; ++i)
        {
            parenty = parentx;
            cin >> inp;
            parentx = parent(union_find, inp - 1);
            if (union_find[parentx].second > union_find[parenty].second)
            {
                union_find[parenty].first = parentx;
                parentx = parent(union_find, parenty);
            }
            else
            {
                union_find[parentx].first = parenty;
                parentx = parent(union_find, parentx);
            }
        }
    }
    auto end = people - 1;
    for (int i = 0; i < end; ++i)
        cout << union_find[parent(union_find, i)].second << " ";
    cout << union_find[parent(union_find, end)].second << "\n";
    return 0;
}
