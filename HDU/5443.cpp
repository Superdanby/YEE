//httpacm.hdu.edu.cnshowproblem.phppid=5443

#include <iostream>
using namespace std;
int cases, water, query;

int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        scanf("%d", &water);
        int W[water];
        for(int x=0; x<water; x++)
            scanf("%d", &W[x]);
        scanf("%d", &query);
        int Max, front, back;
        for(int x=0; x<query; x++)
        {
            Max=0;
            scanf("%d %d", &front, &back);
            for(int x=front-1; x<back; x++)
                Max=max(Max, W[x]);
            printf("%d\n", Max);
        }
    }
    return 0;
}
