#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int houses;
    cin>>houses;
    int fr[houses-1],cr[houses],sr[houses-1],cnt[houses];
    for(int x=0; x<houses-1; x++)
    {
        int in;
        cin>>in;
        fr[x]=in;
    }
    for(int x=0; x<houses-1; x++)
    {
        int in;
        cin>>in;
        sr[x]=in;
    }
    for(int x=0; x<houses; x++)
    {
        int in;
        cin>>in;
        cr[x]=in;
    }
    for(int x=0; x<houses; x++)
    {
        int cntf=0,cnts=0;
        for(int y=0; y<x; y++)
            cntf=cntf+fr[y];
        for(int c =x ; c<houses-1; c++)
            cnts=cnts+sr[c];
        cnt[x]=cntf+cnts+cr[x];
//        cout<<cnt[x]<<" ";
    }
    sort(cnt,cnt+houses);
    int ans;
    ans=cnt[0]+cnt[1];
    cout<<ans;
    return 0;
}
