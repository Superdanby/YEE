//http://acm.hdu.edu.cn/showproblem.php?pid=1848
//Combinatorial Game Theory

/*
#include <bits/stdc++.h>
#define Max 1000
#define MaxSG 90
using namespace std;
int SG[2000];
int fibo[90]={0};
int topdown(int num)
{//build SG table
    if(SG[num]!=-1)
    {//return if SG[num] was calculated before
        return SG[num];
    }
    else
    {
        bool check[MaxSG]={0};//SG subvalue existance check
        //SG subvalue
        for(int x=1; x<MaxSG; x++)
        {
            if(num-fibo[x]<0)
                break;
            check[topdown(num-fibo[x])]=1;
            assert(topdown(num-fibo[x]) < MaxSG);
        }
        //SG value
        for(int x=0; x<MaxSG; x++)
        {//Get SG value
            if(check[x]==0)
            {
                SG[num]=x;
                break;
            }
        }
    }
    return SG[num];
}
int main()
{
    int fir, sec, third;
    //initialize SG table
    memset(SG, -1, sizeof(SG));
    SG[0]=0;
    //build Fibonacci table
    fibo[1]=1;
    fibo[2]=2;
    for(int x=3;; x++)
    {
        fibo[x]=fibo[x-1]+fibo[x-2];
        if(fibo[x]>Max)
            break;
    }
    while(cin>>fir>>sec>>third)
    {
        if(!(fir || sec || third))
        break;

        int ansfir, anssec, ansthird;
        ansfir=topdown(fir);
        anssec=topdown(sec);
        ansthird=topdown(third);

        //XOR the three piles
        ansfir=ansfir^anssec;
        ansfir^=ansthird;
        if(ansfir)
            cout<<"Fibo\n";
        else
            cout<<"Nacci\n";
    }
    return 0;
}
*/

#include <bits/stdc++.h>
#define Max 1000
#define MaxSG 90
using namespace std;
int SG[2000];
int fibo[90]={0};
int last=1;
int GetSG(int num)
{//Build SG table from last to num.
    //This is correct because fibo{1}=1.
    if(num<last)
        return SG[num];
    for(; last<=num; last++)
    {
        set<int> check;//SG subvalue existance check
        for(int y=1; y<90; y++)
        {
            if(last-fibo[y]<0)
                break;
            check.insert(SG[last-fibo[y]]);
            assert(SG[last-fibo[y]] < MaxSG);
        }
        //SG value
        for(int y=0; y<MaxSG; y++)
        {//Get SG value
            if(check.find(y)==check.end())
            {
                SG[last]=y;
                break;
            }
        }
        //cout<<SG[num]<<" ";
    }
    return SG[num];
}
int main()
{
    int fir, sec, third;
    //initialize SG table
    memset(SG, -1, sizeof(SG));
    SG[0]=0;
    //build Fibonacci table
    fibo[1]=1;
    fibo[2]=2;
    for(int x=3;; x++)
    {
        fibo[x]=fibo[x-1]+fibo[x-2];
        if(fibo[x]>Max)
            break;
    }
    while(cin>>fir>>sec>>third)
    {
        if(!(fir || sec || third))
        break;

        int ansfir, anssec, ansthird;
        ansfir=GetSG(fir);
        anssec=GetSG(sec);
        ansthird=GetSG(third);

        //XOR the three piles
        ansfir=ansfir^anssec;
        ansfir^=ansthird;
        if(ansfir)
            cout<<"Fibo\n";
        else
            cout<<"Nacci\n";
    }
    return 0;
}
