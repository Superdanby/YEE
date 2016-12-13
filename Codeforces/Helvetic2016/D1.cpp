#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int height, width;
    cin>>height>>width;
    string inp;
    cin.ignore();
    for(int x=0; x<height; x++)
    {
//        cout<<x<<"\n";
        getline(cin,inp);
//        cout<<inp<<"\n";
    }
    int cnt=0;
    char check;
//    cout<<inp<<"\n";
    for(auto c:inp)
    {
        if(c!=check && c=='B')
            ++cnt;
        check=c;
    }
    cout<<cnt<<"\n";
    return 0;
}
