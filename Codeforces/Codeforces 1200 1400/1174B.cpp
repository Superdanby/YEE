#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int nums;
    cin >> nums;
    bool odd = false, even = false;
    vector<int> vec;
    int inp;
    while (nums--)
    {
        cin >> inp;
        if (inp & 1)
            odd = true;
        else
            even = true;
        vec.push_back(inp);
    }
    if (odd && even)
        sort(vec.begin(), vec.end());
    auto end = vec.end() - 1;
    for (auto it = vec.begin(); it != end; ++it)
        cout << *it << " ";
    cout << *end << "\n";
    return 0;
}
