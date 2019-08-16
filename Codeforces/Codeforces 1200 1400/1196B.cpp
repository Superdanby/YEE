#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        int nums, parts;
        cin >> nums >> parts;
        int odds = 0;
        vector<int> inp(nums);
        vector<int> border;
        int cnt = 0;
        for (auto & x: inp)
        {
            cin >> x;
            ++cnt;
            if (x % 2 == 1)
            {
                ++odds;
                border.push_back(cnt);
            }
        }
        if (odds >= parts && (odds - parts) % 2 == 0)
        {
            cout << "YES\n";
            for (int i = 0; i < parts - 1; ++i)
                cout << border[i] << " ";
            cout << nums << "\n";
            continue;
        }
        cout << "NO\n";
    }
    return 0;
}
