//http://acm.hdu.edu.cn/showproblem.php?pid=5437
//Customized priority_queue
//traps are everywhere
#include <bits/stdc++.h>
#include <cstdio>
#include <queue>
using namespace std;
#define MAX 150010
int cases;
int npeo, nop, nque;
char name[MAX][210];
pair<int, int> process[MAX];
struct unit{
    int nameidx, value;
};
unit D[MAX];
unit ans[MAX];
class cmp{//compare class
public:
    bool operator()(const unit &A, const unit &B)
    {
        if(A.value==B.value)
            return A.nameidx>B.nameidx;
        return A.value<B.value;
    }
};
int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d %d %d", &npeo, &nop, &nque);
        for(int i=0; i<npeo; i++)
        {
            scanf("%s", name[i]);
            scanf("%d", &D[i].value);
            D[i].nameidx=i;
        }
        int query, Dptr=0, ansptr=0;
        priority_queue<unit, vector<unit>, cmp> q;
        for(int i=0; i<nop; i++)
        {
            scanf("%d %d", &process[i].first, &process[i].second);
        }
        sort(process,process+nop);//very important
        for(int i=0; i<nop; i++)
        {
            for(; Dptr<process[i].first; Dptr++)
            {
                q.push(D[Dptr]);
            }
            for(int j=0; j<process[i].second && !q.empty(); j++)
            {
                ans[ansptr++]=q.top();
                q.pop();
            }
        }
        while(Dptr<npeo)//lets remaining friends in
            q.push(D[Dptr++]);
        while(!q.empty())
        {
            ans[ansptr++]=q.top();
            q.pop();
        }
        for(int i=0; i<nque; i++)
        {
            scanf("%d", &query);
            printf("%s", name[ans[query-1].nameidx]);
            if(i!=nque-1)
                printf(" ");
        }
        printf("\n");
    }
    return 0;
}
