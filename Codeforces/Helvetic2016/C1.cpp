#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Graph(1001,vector<int>(0,0));
int total;
bool visited[1001];
void solve(int start)
{
    visited[start]=true;
    for(int x=0; x<Graph[start].size(); x++)
    {
        if(!visited[Graph[start][x]])
            solve(Graph[start][x]);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int brains;
    cin>>brains>>total;
    if(brains-1!=total)
    {
        cout<<"no\n";
        return 0;
    }
    int inp1,inp2;
    for(int x=0; x<total; x++)
    {
        cin>>inp1>>inp2;
        Graph[inp1].push_back(inp2);
        Graph[inp2].push_back(inp1);
    }
    memset(visited, 0, sizeof(visited));
    solve(1);
    for(int x=1; x<=brains; x++)
    {
        if(!visited[x])
        {
            cout<<"no\n";
            return 0;
        }
    }
    cout<<"yes\n";
    return 0;
}
