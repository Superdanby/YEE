#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int tests;
    cin >> tests;
    int inp, ans = 0, cnt = 1, prev;
    cin >> prev;
    while (--tests)
    {
        cin >> inp;
        if (prev * 2 < inp)
        {
            ans = ans > cnt ? ans : cnt;
            cnt = 1;
        }
        else
            ++cnt;
        prev = inp;
    }
    cout << (ans > cnt ? ans : cnt) << "\n";
    return 0;
}
