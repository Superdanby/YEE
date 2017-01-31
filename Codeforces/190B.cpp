#include <bits/stdc++.h>
using namespace std;
typedef long double ld;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    ld ff, fs, fr, sf, ss, sr;
    cin>>ff>>fs>>fr>>sf>>ss>>sr;
    ld ans=sqrt((ff-sf)*(ff-sf)+(fs-ss)*(fs-ss));
    if(ans-fr-sr>0)
        cout<<fixed<<setprecision(15)<<(ans-fr-sr)/(ld)2<<"\n";
    else if((ans+fr-sr>0 && sr>fr) || (ans-fr+sr>0 && fr>sr))
        cout<<0<<"\n";
    else if(fr-ans-sr>0)
        cout<<fixed<<setprecision(15)<<(fr-ans-sr)/(ld)2<<"\n";
    else if(sr-ans-fr>0)
        cout<<fixed<<setprecision(15)<<(sr-ans-fr)/(ld)2<<"\n";
    else
        cout<<0<<"\n";
    return 0;
}
