#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int inp;
    cin >> inp;
    if (inp & 1)
        cout << "0\n";
    else
        cout << (1L << (inp / 2)) << "\n";
    return 0;
}
