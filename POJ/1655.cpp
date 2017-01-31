//http://poj.org/problem?id=1655
//Tree centroid

#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
int vertices, MAX;
int pv;//previous node
int cases;
int inp1, inp2;
vector<vector<int> > graph(20000+10);
vector<int> nums(20000+10);//number of vertices under any vertex +1(and itself)

void setnum(int node, int &centr)
{//dfs
    if(centr!=-1)
        return;
    nums[node]=1;
    for(int x=0; x<graph[node].size(); x++)
    {
        if(!nums[graph[node][x]])//graph[node][x] was visited and it is a parent node if nums[graph[node][x]] isn't 0
        {
            setnum(graph[node][x], centr);
            if(centr!=-1)
                break;
            if(MAX<nums[graph[node][x]])
            {//nums[node's child]>
                MAX=nums[graph[node][x]];
                pv=graph[node][x];
            }
            nums[node]+=nums[graph[node][x]];
        }
    }
    if(nums[node]>vertices/2)
    {
        centr=node;
        if(vertices-MAX==MAX)//only occurs when the biggest child of the current centr is the possible answer
            centr=min(centr,pv);
        else
            MAX=max(MAX, vertices-nums[node]);
        printf("%d %d\n", centr, MAX);
    }
    return;
}
void centroid(int node)
{
    fill(nums.begin(), nums.end(), 0);
    int centr=-1;//answer candidate
    setnum(node, centr);
    return;
}
int main()
{
    scanf("%d", &cases);
    while(cases--)
    {
        //clear graph
        for(int x=1; x<=vertices; x++)
            graph[x].clear();
        MAX=0, pv=1;//pv(previous vertex): start from vertex 1(can be changed)
        scanf("%d", &vertices);
        for(int x=0; x<vertices-1; x++)
        {
            scanf("%d %d", &inp1, &inp2);
            graph[inp1].push_back(inp2);
            graph[inp2].push_back(inp1);
        }
        centroid(pv);
    }
    return 0;
}
