#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int nodes;
        scanf("%d", &nodes);
        int Map[nodes+1][nodes+1];
        memset(Map, 0, sizeof(Map));
        for(int x=0; x<nodes; x++)
        {
            for(int y=0; y<nodes; y++)
            {
                scanf("%d", &Map[x][y]);
            }
        }
/*        for(int x=0; x<nodes; x++)
        {
            for(int y=0; y<nodes; y++)
            {
                printf("%d ", Map[x][y]);
            }
            printf("\n");
        }
*/        int ignore;
        scanf("%d", &ignore);
        int no=1;
        int cnt=nodes*(nodes-1)/2;
        for(int x=1; cnt && no && x<=nodes; x++)
        {
            int stack[nodes], sidx=0;
            stack[0]=x;
            cnt=nodes*(nodes-1)/2;
            while(sidx>=0 && cnt && no)
            {
                --cnt;
                int curnode=stack[sidx];
                --sidx;
//                printf("%d %d\n", curnode, no);
                for(int y=x; no && y<=nodes; y++)
                {
                    if(Map[curnode][y])
                    {
//                        printf("%d %d\n", y, x);
                        if(y==x)
                        {
//                            printf("in\n");
                            no=0;
                            break;
                        }
                        stack[++sidx]=y;
                    }
                }
            }
        }
//        printf("%d\n", no);
        if(no && cnt)
            printf("No\n");
        else
            printf("Yes\n");
    }
    return 0;
}
