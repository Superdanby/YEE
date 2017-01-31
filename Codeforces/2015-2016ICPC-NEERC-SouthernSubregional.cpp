//http://codeforces.com/problemset/problem/589/F
//Max Flow, Binary Search
//find answer with Binary search
//S{all seconds}, T{all dishes}
#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to, cap, rev;
    Edge(int a, int b, int c)
    {
        to = a;
        cap = b;
        rev = c;
    }
};
const int INF = 0x3f3f3f3f;
const int MAX_V = 10000 + 100 + 2 + 100;
vector<vector<Edge>> g(MAX_V);
int level[MAX_V];
int iter[MAX_V];
inline void add_edge(int u, int v, int cap)
{//Construct Flow Network
    g[u].push_back((Edge) {
        v, cap, (int)g[v].size()
    });
    g[v].push_back((Edge) {
        u, 0, (int)g[u].size() - 1
    });
}
void bfs(int s)
{
    memset(level, -1, sizeof(level)); // 用fill
    queue<int> q;
    level[s] = 0;
    q.push(s);
    while (!q.empty()) {
        int v = q.front();
        q.pop();
        for (int i = 0; i < int(g[v].size()); i++) {
            const Edge &e = g[v][i];
            if (e.cap > 0 && level[e.to] < 0) {
                level[e.to] = level[v] + 1;
                q.push(e.to);
            }
        }
    }
}
int dfs(int v, int t, int f)
{
    if (v == t)
        return f;
    for (int &i = iter[v]; i < int(g[v].size()); i++) { // &很重要
        Edge &e = g[v][i];
        if (e.cap > 0 && level[v] < level[e.to]) {
            int d = dfs(e.to, t, min(f, e.cap));
            if (d > 0) {
                e.cap -= d;
                g[e.to][e.rev].cap += d;
                return d;
            }
        }
    }
    return 0;
}
int max_flow(int s, int t)   // Dinic algorithm
{
    int flow = 0;
    for (;;) {
        bfs(s);//get level with bfs
        if (level[t] < 0)
            return flow;
        memset(iter, 0, sizeof(iter));
        int f;
        while ((f = dfs(s, t, INF)) > 0) {
            flow += f;
        }
    }
}

int main()
{
    int input;
    cin>>input;
    pair<int,int> data[input+1];
    int Max=0, Min=0x7f7f7f7f;
    for(int x=1; x<=input; x++)
    {
        cin>>data[x].first>>data[x].second;
        Max=max(Max,data[x].second);
        Min=min(data[x].first,Min);
    }

    int ub=Max+1, lb=0, pivot=(ub+lb)/2;

    while(ub-lb>1)
    {
        pivot=(lb+ub)/2;
        for(int x=0; x<=Max+input+1; x++)
            g[x].clear();//clear all edges
        for(int x=Min+1; x<=Max; x++)
        {
            add_edge(0,x,1);//Add edges from the source to every element in S(excluding the source) with weight 1
        }
        for(int x=1; x<=input; x++)
        {
            for(int y=data[x].first+1; y<=data[x].second; y++)
            {
                add_edge(y,Max+x,1);//Add edges from S(excluding the source) to T(excluding the sink)
            }
        }
        for(int x=1; x<=input; x++)
        {
            add_edge(Max+x, Max+input+1, pivot);//Add edges from every element in T(excluding the sink) to the sink with weight pivot
        }
        int ans=max_flow(0,Max+input+1);//Get max flow from source to sink
        if(ans==input*pivot)
            lb=pivot;
        else
            ub=pivot;
    }
    cout<<lb*input<<"\n";
    return 0;
}
