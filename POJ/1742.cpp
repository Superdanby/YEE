//http://poj.org/problem?id=1742
//Bounded Knapsack -> 0/1 Knapsack with binary conversion
//Operation Speed on POJ bitOR(|)>plus(+)>OR(||)
//initializations done in global scope is better than that in local scopes
#include <cstdio>
#include <vector>
#include <functional>
//#include <cassert>
//#include <bits/stdc++.h>
using namespace std;
bool dp[100000+1];
int main()
{
    int nums, Max;
    while(scanf("%d %d", &nums, &Max))
    {
        if(!(nums || Max))
            break;//breaks when num==0 && Max==0
        int ovalue[nums], quant[nums];
        for(int x=0; x<nums; x++)
            scanf("%d", &ovalue[x]);
        for(int x=0; x<nums; x++)
            scanf("%d", &quant[x]);
        vector<int> value;
        for(int x=0; x<nums; x++)
        {//binary conversion
            for(int sub=1; sub<=quant[x]; sub<<=1)
            {
                quant[x]-=sub;
                value.push_back(sub*ovalue[x]);
            }
            if(quant[x])
                value.push_back(quant[x]*ovalue[x]);
        }

        //dp[] initialization
        fill(dp, dp + Max + 1, false);
        dp[0]=1;

        for(int x=0; x<value.size(); x++)
        {// 0/1 Knapsack
            for(int y=Max; y>=value[x]; y--)
            {
                dp[y]=(dp[y] | dp[y-value[x]]);
            }
        }
        int cnt=0;
        for(int x=1; x<=Max; x++)
        {
            if(dp[x])
                ++cnt;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
