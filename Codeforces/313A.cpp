#include <iostream>

using namespace std;

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int in;
        cin>>in;
        if(in==1)
        {
            cout<<"-1";
            break;
        }
        else if(t==0)
            cout<<"1";
    }
    return 0;
}