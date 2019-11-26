#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int length, ans = 0;
    cin >> length;
    string A, B;
    cin >> A >> B;
    for (size_t i = 0; i < length - 1; ++i)
    {
        if (A[i] != B[i])
        {
            if (A[i + 1] != B[i + 1] && A[i + 1] != A[i])
            {
                ++ans;
                swap(A[i + 1], A[i]);
                ++i;
            }
            else
                ++ans;
        }
    }
    if (A.back() != B.back())
        ++ans;
    cout << ans << "\n";
    return 0;
}
