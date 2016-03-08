#include <bits/stdc++.h>
using namespace std;
/*
bool cmp(const int &a, const int &b)
{
    return a>b;
}
*/
void dfs(vector<int> tree[],int parent, int child, int &Max, vector<bool> visited, vector<int> *Record)
{
    visited[parent]=true;
    cout<<"P"<<parent<<"C"<<tree[parent][child]<<"Csize"<<tree[tree[parent][child]].size()<<"\n";
    cout<<"Q"<<parent<<" "<<tree[parent][child]<<" "<<Record[parent][tree[parent][child]]<<"\n";
    if(Record[parent][tree[parent][child]]!=0)
    {
        Max+=Record[parent][tree[parent][child]];cout<<" R Max"<<Max<<"\n";
    }
    for(int x=0; x<tree[tree[parent][child]].size(); x++)
    {
        if(visited[tree[tree[parent][child]][x]]==false)
        {
            dfs(tree,tree[parent][child],x,Max,visited,Record);
            //Max+=tree[tree[parent][child]].size();
        }
    }
    ++Max;
    cout<<"CommonMax"<<Max<<"\n";
    Record[parent][tree[parent][child]]=Max;
    cout<<"Record["<<parent<<"]["<<tree[parent][child]<<"]"<<Record[parent][tree[parent][child]]<<"\n";
    return;
}
int main()
{
    int cases;
    cin>>cases;
    while(cases--)
    {
        int nodes;
        cin>>nodes;
        vector<int> tree[nodes];
        vector<int> record[nodes];
        vector<int> *Record;
        Record=record;
        int inp1, inp2;
        for(int x=0; x<nodes-1; x++)
        {
            cin>>inp1>>inp2;
            tree[inp1].push_back(inp2);
            tree[inp2].push_back(inp1);
            record[inp1].push_back(0);
            record[inp2].push_back(0);
        }
        int ans=0;
        unsigned int Max=0;
        --Max;
        for(int x=0; x<nodes; x++)
        {
            int tempmax=0;
            for(int y=0; y<tree[x].size(); y++)
            {
                cout<<"x,y"<<x<<','<<y<<" "<<record[x][tree[x][y]]<<"\n";
                int cnt=0;
                if(record[x][tree[x][y]]!=0)
                {
                    cnt=record[x][tree[x][y]];
                }
                else
                {
                    vector<bool> visited(nodes,false);
                    dfs(tree,x,y,cnt,visited,Record);
                    record[x][tree[x][y]]=cnt;
                }
                if(tempmax<cnt)
                {
                    tempmax=cnt;
                }
                cout<<"cnt"<<cnt<<" ";
                cout<<"tempmax"<<tempmax<<"\n";
            }
            if(tempmax<Max)
            {
                Max=tempmax;
                ans=x;
            }
//            cout<<"Max"<<Max<<"\n";
        }

        cout<<ans<<"\n";
    }
    return 0;
}
