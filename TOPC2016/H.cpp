#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int length, cnt=0;
        scanf("%d", &length);
        int d1[length], d2[length];
        for(int x=0; x<length; x++)
        {
            scanf("%d", &(d1[x]));
        }
        for(int x=0; x<length; x++)
        {
            scanf("%d", &(d2[x]));
            if(d2[x]!=d1[x])
                ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
