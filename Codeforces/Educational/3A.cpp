#include <bits/stdc++.h>
using namespace std;
bool Big(const int &a, const int &b)
{
    return a>b;
}
int main()
{
    int NDrives;
    cin>>NDrives;
    int EachDSize[NDrives];
    int FileSize;
    cin>>FileSize;
    for(int x=0; x<NDrives; x++)
    {
        cin>>EachDSize[x];
    }
    sort(EachDSize, EachDSize+NDrives, Big);
    int sum=0, cnt=0;
    for(int x=0; x<NDrives; x++)
    {
        ++cnt;
        sum+=EachDSize[x];
        if(sum>=FileSize)
            break;
    }
    cout<<cnt;
    return 0;
}
