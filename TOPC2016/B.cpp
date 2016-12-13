#include <bits/stdc++.h>
using namespace std;
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int edge1;
        cin>>edge1;
        int inp1, inp2;
        for(int x=0; x<edge1; x++)
        {
            cin>>inp1>>inp2;
        }
        int edge2;
        cin>>edge2;
        for(int x=0; x<edge2; x++)
        {
            cin>>inp1>>inp2;
        }
        if(edge1!=edge2)
            cout<<"no\n";
        else
            cout<<"yes\n";
    }
    return 0;
}
