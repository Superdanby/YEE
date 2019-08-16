#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int length;
    cin >> length;
    string inp;
    cin >> inp;
    vector<vector<int>> pos(26, vector<int>(1, 0));
    for (int i = 0; i < length; ++i)
    {
        int letter = inp[i] - 'a';
        pos[letter].emplace_back(i + 1);
    }
    int queries;
    cin >> queries;
    string cmp;
    while (queries--)
    {
        cin >> cmp;
        vector<int> cnt(26, 0);
        for(auto x: cmp)
            ++cnt[x - 'a'];
        int ans = 0;
        for(int i = 0; i < cnt.size(); ++i)
            ans = pos[i][cnt[i]] > ans ? pos[i][cnt[i]] : ans;
        cout << ans << "\n";
    }
    return 0;
}
