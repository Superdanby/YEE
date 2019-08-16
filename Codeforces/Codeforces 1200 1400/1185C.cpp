#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums, cost = 0, inp, limit;
    cin >> nums >> limit;
    priority_queue<int> pq;
    priority_queue<int, vector<int>, greater<int>> buffer;
    vector<int> ans;
    for (int i = 0; i < nums; ++i)
    {
        cin >> inp;
        cost += inp;
        while (cost > limit)
        {
            buffer.push(pq.top());
            pq.pop();
            cost -= buffer.top();
        }
        ans.push_back(buffer.size());
        cost -= inp;
        buffer.push(inp);
        while (!buffer.empty() && cost + buffer.top() <= limit)
        {
            cost += buffer.top();
            pq.push(buffer.top());
            buffer.pop();
        }
    }
    auto it = ans.begin();
    auto endit = ans.end();
    --endit;
    for (; it != endit; ++it)
    {
        cout << *it << " ";
    }
    cout << *endit << "\n";
    return 0;
}
