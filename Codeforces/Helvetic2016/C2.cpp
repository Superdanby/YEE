#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Graph(100001,vector<int>(0,0));
int total, maxdepth=0, flag;
bool visited[100001];
void solve(int start, int depth)
{
    visited[start]=true;
    for(int x=0; x<Graph[start].size(); x++)
    {
        if(!visited[Graph[start][x]])
            solve(Graph[start][x], depth+1);
    }
    if(maxdepth<depth)
    {
        maxdepth=depth;
        flag=start;
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int brains;
    cin>>brains>>total;
    int inp1,inp2;
    for(int x=0; x<total; x++)
    {
        cin>>inp1>>inp2;
        Graph[inp1].push_back(inp2);
        Graph[inp2].push_back(inp1);
    }
    memset(visited, 0, sizeof(visited));
    solve(1,0);
//    cout<<flag<<"f\n";
    memset(visited, 0, sizeof(visited));
    solve(flag,0);
    cout<<maxdepth<<"\n";
    return 0;
}
