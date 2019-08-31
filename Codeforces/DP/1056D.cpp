#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nodes;
    cin >> nodes;
    vector<int> parent(nodes + 1), rank(nodes + 1, 1);
    unordered_map<int, queue<int>> children;
    rank[0] = 0;
    int inp;
    for (size_t i = 2; i <= nodes; ++i)
    {
        cin >> inp;
        children[inp].push(i);
        rank[inp] = 0;
    }
    stack<int> get_leaves({1});
    while(!get_leaves.empty())
    {
        int node = get_leaves.top();
        if (children[node].size())
        {
            int child = children[node].front();
            if (!rank[child])
                get_leaves.push(child);
            else
            {
                rank[node] += rank[child];
                children[node].pop();
            }
        }
        else
            get_leaves.pop();
    }
    sort(rank.begin(), rank.end());
    for (size_t i = 1; i < nodes; ++i)
    {
        cout << rank[i] << " ";
    }
    cout << rank.back() << "\n";
    return 0;
}
