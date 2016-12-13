#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int roads;
        scanf("%d", &roads);
        int start, end;
        scanf("%d %d", &start, &end);
        int **Map=malloc(roads*sizeof(int*)+1);
        for(int x=0; x<roads; x++)
        {
            Map[x]=malloc(roads*sizeof(int));
            memset(Map[x],-1, roads*sizeof(int));
        }
        for(int x=0; x<roads; x++)
        {
            int from, to;
            scanf("%d %d", &from, &to);
            scanf("%d", &Map[from][to]);
        }
/*        for(int x=0; x<roads; x++)
        {
            for(int y=0; y<roads; y++)
            {
                printf("%d ", Map[x][y]);
            }
            printf("\n");
        }
*/        int ignore;
        scanf("%d", &ignore);
        int mincost[roads];
        memset(mincost,0x3f3f3f3f, sizeof(mincost));
        int stack[roads];
        memset(stack,-1, sizeof(stack));
        int sidx=0;
        stack[0]=start;
        mincost[start]=0;
        while(sidx>=0)
        {
            int curnode=stack[sidx];
            --sidx;
            for(int x=0; curnode!=end && x<roads; x++)
            {
                if(Map[curnode][x]!=-1 && mincost[curnode]+Map[curnode][x]<mincost[x])
                {
                    mincost[x]=mincost[curnode]+Map[curnode][x];
                    stack[++sidx]=x;
                }
            }
        }
        printf("%d\n", mincost[end]);
    }
    return 0;
}
