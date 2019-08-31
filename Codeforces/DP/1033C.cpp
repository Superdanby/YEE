#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    vector<int> num(nums);
    for (auto && x: num)
        cin >> x;
    vector<vector<int>> graph(nums, vector<int>());
    vector<bool> A(nums, false), B(nums, true);
    for (size_t i = 0; i < num.size(); ++i)
    {
        for (size_t j = i % num[i]; j < nums; j += num[i])
            if (num[j] > num[i])
            {
                B[i] = false;
                graph[j].push_back(i);
            }
    }
    queue<int> traverse;
    for (size_t i = 0; i < B.size(); ++i)
    {
        if (B[i])
            traverse.push(i);
    }
    while(!traverse.empty())
    {
        size_t idx = traverse.front();
        traverse.pop();
        bool insert = false;
        for (auto x: graph[idx])
        {
            if (A[idx] && !B[x])
            {
                B[x] = true;
                insert = true;
            }
            if (B[idx] && !A[x])
            {
                A[x] = true;
                insert = true;
            }
            if (insert)
                traverse.push(x);
        }
    }
    for (auto x: A)
        if (x)
            cout << "A";
        else
            cout << "B";
    cout << "\n";
    return 0;
}
