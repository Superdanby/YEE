#include <iostream>

using namespace std;

int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        long long sum=0,input;
        cin>>input;
        sum+=input*(input+1)/2;
        for(long long x=1;x<=input;x*=2)
        {
                sum-=x*2;
//            cout<<sum<<" ";
        }
        cout<<sum<<"\n";
    }
    return 0;
}
