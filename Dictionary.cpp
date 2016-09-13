#include <bits/stdc++.h>
using namespace std;
#define Lowb 8
#define Upb 10
void Num(int Low, int Up)
{
    for(int x=Low; x<Up+1; x++)
    {
        int Max=pow(10,x);
//        cout<<Max<<"max\n";
        for(int y=0; y<Max; y++)
        {
            cout<<setfill('0')<<setw(x)<<y<<"\n";
        }
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    Num(Lowb,Upb);
    return 0;
}
