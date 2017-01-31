#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int qty, days, mcons=0, cons=0;
    string inp;
    cin>>qty>>days;
    string cmp(qty,'1');
//    cout<<cmp;
    for(int x=0; x<days; x++)
    {
        bool yes=false;
        cin>>inp;
        if(cmp!=inp)
        {
            yes=true;
        }
//        cout<<boolalpha<<yes<<"\n";
        if(yes)
            ++cons;
        else
            cons=0;
        mcons=max(mcons,cons);
    }
    cout<<mcons<<"\n";
    return 0;
}
