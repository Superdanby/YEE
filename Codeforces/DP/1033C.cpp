#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    vector<int> num(nums);
    priority_queue<pair<int, int>> traverse;
    for (int i = 0; i < nums; ++i)
    {
        cin >> num[i];
        traverse.push(make_pair(num[i], i));
    }
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
    while(!traverse.empty())
    {
        auto [val, idx] = traverse.top();
        traverse.pop();
        for (auto x: graph[idx])
        {
            if (A[idx] && !B[x] && !A[x])
            {
                B[x] = true;
            }
            if (B[idx] && !A[x])
            {
                A[x] = true;
                B[x] = false;
            }
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
