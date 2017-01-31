//httpacm.hdu.edu.cnshowproblem.phppid=5438
//dfs
#include <cstdio>
#include <vector>
using namespace std;
struct unit{
    int who;
    int idx;
    unit(int A){
        who=A;
        idx=0;
    }
};
int cases, ponds, pipes;
vector<int> val(10010);
vector< vector<unit> > g(10010);
void del(int pond)
{
    for(int i=1; g[pond][0].who==1 && i<g[pond].size(); i++)
    {
        if(g[pond][i].idx)
        {
            --g[g[pond][i].who][0].who;
            g[g[pond][i].who][g[pond][i].idx].idx=0;
            g[pond][i].idx=0;
            --g[pond][0].who;
            del(g[pond][i].who);
        }
    }
    return;
}
int cnt(int pond, long long &sum)
{
    if(!g[pond][0].who)
        return 0;
    int accum=0;
    sum+=val[pond];
    g[pond][0].who=0;
    for(int i=1; i<g[pond].size(); i++)
    {
        if(g[pond][i].idx)
        {
            accum+=cnt(g[pond][i].who, sum);
        }
    }
    return accum+1;
}
int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d", &ponds, &pipes);
        for(int i=1; i<=ponds; i++)
        {
            scanf("%d", &val[i]);
            g[i].clear();
            g[i].push_back(unit(0));
        }
        int inp1, inp2;
        for(int i=1; i<=pipes; i++)
        {
            scanf("%d %d", &inp1, &inp2);
            g[inp1].push_back(unit(inp2));
            g[inp2].push_back(unit(inp1));
            g[inp1].back().idx=g[inp2].size()-1;
            g[inp2].back().idx=g[inp1].size()-1;
            ++g[inp1][0].who;
            ++g[inp2][0].who;
        }

        for(int i=1; i<=ponds; i++)
            if(g[i][0].who==1)
                del(i);
        long long ans=0;
        for(int i=1; i<=ponds; i++)
            if(g[i][0].who>0)
            {
                long long sum=0;
                if(cnt(i, sum)%2)
                    ans+=sum;
            }
        printf("%lld\n", ans);
    }
    return 0;
}
