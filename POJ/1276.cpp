//http://poj.org/problem?id=1276
//Bounded Knapsack
//optional: -> 0/1 knapsack

#include <iostream>
#include <sstream>
#include <cstring>
#include <vector>
#include <functional>
//#include <cassert>
//#include <bits/stdc++.h>
using namespace std;
int main()
{
    int goal, types;
    while(cin>>goal>>types)
    {
        //assert(inp.length()<1000000); Don't use string. Don't even think about it!
        pair<int,int> data[types];
        for(int x=0; x<types; x++)
            cin>>data[x].first>>data[x].second;
        vector<int> value;
        for(int x=0; x<types; x++)
        {//binary conversion
            int sub=1;
            while(data[x].first)
            {
                if(sub>data[x].first)
                {
                    if(data[x].first)
                        value.push_back(data[x].first*data[x].second);
                    break;
                }
                data[x].first-=sub;
                value.push_back(sub*data[x].second);
                sub<<=1;
            }
        }
        bool dp[goal+1];
        memset(dp, 0, sizeof(dp));
        dp[0]=1;
        for(int x=0; x<value.size(); x++)
        {// 0/1 Knapsack
            for(int y=goal; y>=value[x]; y--)
            {
                dp[y]=(dp[y-value[x]] || dp[y]);
            }
        }
        for(int x=goal; x>=0; x--)
        {
            if(dp[x])
            {
                cout<<x<<"\n";
                break;
            }
        }
    }
    return 0;
}
