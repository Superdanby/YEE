#include <bits/stdc++.h>
using namespace std;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    char inp;
    while(cin>>inp)
    {
        if(inp>='A' && inp<='Z')
            inp=inp-'A'+'a';
        if(inp!='a' && inp!='e' && inp!='i' && inp!='o' && inp!='u' && inp!='y' )
            cout<<"."<<inp;
    }
    cout<<"\n";
    return 0;
}
