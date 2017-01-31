//http://codeforces.com/problemset/problem/603/C
//Combinatorial Game Theory
#include <bits/stdc++.h>
using namespace std;
int topdown(int num)
{//SG value
    if(num==3)
        return 1;
    if(num%2)
        return 0;
    int value=topdown(num/2);
    //assert(value<3);
    if(value==1)
        return 2;
    else if(value==2 || !value)
        return 1;
}
int main()
{
    int piles, k;
    cin>>piles>>k;
    int cows[piles];
    for(int x=0; x<piles; x++)
    {
        cin>>cows[x];
        if(!(k%2))
        {
            if(cows[x]>2)
            {
                if(cows[x]%2)
                    cows[x]=0;
                else
                    cows[x]=1;
            }
        }
        else
        {
            if(cows[x]==2)
                cows[x]=0;
            if(cows[x]>2)
                cows[x]=topdown(cows[x]);
        }
    }
    int ans=0;
    for(int x=0; x<piles; x++)
    {//merge piles
        ans^=cows[x];
    }
    if(ans)
        cout<<"Kevin\n";
    else
        cout<<"Nicky\n";
    return 0;
