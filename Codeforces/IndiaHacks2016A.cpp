#include <bits/stdc++.h>
using namespace std;
int main()
{
    int balls;
    cin>>balls;
    int ball[1001];
    for(int x=0; x<1001; x++)
    {
        ball[x]=0;
    }
    for(int x=0; x<balls; x++)
    {
        int inp;
        cin>>inp;
        ++ball[inp];
//        cout<<inp;
    }
    for(int x=0; x<999; x++)
    {
        if((ball[x+2]>0) && (ball[x+1]>0) && (ball[x]>0))
        {
            cout<<"YES";
            return 0;
        }
    }
    cout<<"NO";
    return 0;
}
