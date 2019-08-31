#include <bits/stdc++.h>

using namespace std;

using ll = long long;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    bool ignore = false;
    ll inp, ans = 0, neg_cnt = 0;
    while (nums--)
    {
        cin >> inp;
        if (!inp)
        {
            ignore = true;
            ++ans;
        }
        else if (inp > 0)
            ans += inp - 1;
        else
            ans += -1 - inp, ++neg_cnt;
    }
    if (!ignore && (neg_cnt & 1))
        cout << ans + 2 << "\n";
    else
        cout << ans << "\n";
    return 0;
}
