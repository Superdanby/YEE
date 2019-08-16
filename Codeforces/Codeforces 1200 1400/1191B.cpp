#include <bits/stdc++.h>

using namespace std;

int main()
{
    vector<int> m(10, 0), p(10, 0), s(10, 0);
    int inpn, cnt = 0;
    char inpc;
    while(scanf("%d%c", &inpn, &inpc) == 2)
    {
        if (inpc == 'm')
            ++m[inpn];
        else if (inpc == 'p')
            ++p[inpn];
        else if (inpc == 's')
            ++s[inpn];
    }
    for (auto x: m)
        cnt = x > cnt ? x : cnt;
    if (cnt >= 3)
    {
        printf("0\n");
        return 0;
    }
    for (auto x: p)
        cnt = x > cnt ? x : cnt;
    if (cnt >= 3)
    {
        printf("0\n");
        return 0;
    }
    for (auto x: s)
        cnt = x > cnt ? x : cnt;
    if (cnt >= 3)
    {
        printf("0\n");
        return 0;
    }
    for (int i = 0; i < 8; ++i)
    {
        int local = (m[i] & 1) + (m[i + 1] & 1) + (m[i + 2] & 1);
        cnt = local > cnt ? local : cnt;
    }
    for (int i = 0; i < 8; ++i)
    {
        int local = (p[i] & 1) + (p[i + 1] & 1) + (p[i + 2] & 1);
        cnt = local > cnt ? local : cnt;
    }
    for (int i = 0; i < 8; ++i)
    {
        int local = (s[i] & 1) + (s[i + 1] & 1) + (s[i + 2] & 1);
        cnt = local > cnt ? local : cnt;
    }
    printf("%d\n", 3 - cnt);
    return 0;
}
