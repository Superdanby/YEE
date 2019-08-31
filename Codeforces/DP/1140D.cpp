#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int vertices;
    cin >> vertices;
    int ans = 0;
    for (int i = 2; i < vertices; ++i)
        ans += i * (i + 1);
    cout << ans << "\n";
    return 0;
}
