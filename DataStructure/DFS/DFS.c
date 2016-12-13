#include <stdlib.h>
#include <stdio.h>
#include <string.h>
int main()
{
    int monsters;
    scanf("%d", &monsters);
    int paths;
    scanf("%d", &paths);
    int power;
    scanf("%d", &power);
    int end;
    scanf("%d", &end);
    int Map[monsters][monsters];//adjacecy matrix
    memset(Map,0,sizeof(Map));
    int monster[monsters];
    for(int x=0; x<monsters; x++)
    {
        scanf("%d", monster+x);
    }
    for(int x=0; x<paths; x++)
    {
        int from, to;
        scanf("%d %d", &from, &to);
        Map[from][to]=1;
    }
//    printf("pass\n");
    int loses=0, wins=0;
    int stack[paths];
    memset(stack,-1,sizeof(stack));
    int sidx=0;
    stack[0]=0;
    while(sidx>=0 && power<end)//stack
    {
        int curmon=stack[sidx];
        --sidx;
        if(power>monster[curmon])
        {
            power+=monster[curmon];
            for(int x=monsters-1; x>=0; x--)
            {
                if(Map[curmon][x])
                {
                    ++sidx;
                    stack[sidx]=x;
                }
            }
            ++wins;
            continue;
        }
        ++loses;
    }
    printf("%d %d %d\n", loses, wins, power);
    return 0;
}
