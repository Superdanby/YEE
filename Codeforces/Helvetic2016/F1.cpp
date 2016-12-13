#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> Graph(10001,vector<int>(0));
int total=0, block;
void Print(int a)
{
    for(int x=0; x<a; x++)
    {
        for(int y=0; y<Graph[x].size(); y++)
        {
            cout<<Graph[x][y]<<" ";
        }
        cout<<"\n";
    }
    return;
}
void solve(int start, int depth)
{
//    cout<<start<<"s\n";
    if(depth)
    {
//        cout<<Graph[start].size()<<"size\n";
        total+=Graph[start].size();
        --total;
//        cout<<total<<"t\n";
        return;
    }
    for(int x=0; x<Graph[start].size(); x++)
    {
        if(block!=Graph[start][x])
            solve(Graph[start][x], 1);
    }
    return;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int vertices;
    cin>>vertices;
    int inp1,inp2;
    for(int x=0; x<vertices-1; x++)
    {
        cin>>inp1>>inp2;
        Graph[inp1].push_back(inp2);
        Graph[inp2].push_back(inp1);
    }
//    Print(vertices);
    for(int x=1; x<=vertices; x++)
    {
        block=x;
        solve(x,0);
//        cout<<x<<" "<<total<<"\n";
    }
    cout<<total/2<<"\n";
    return 0;
}
