#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int pairs;
    cin >> pairs;
    while (pairs--)
    {
        string A, B;
        cin >> A >> B;
        if (A.size() > B.size())
        {
            cout << "NO\n";
            continue;
        }
        auto Ait = A.begin(), Bit = B.begin();
        char prev = '\0';
        for(; Bit != B.end(); ++Bit)
        {
            if (Ait != A.end() && *Ait == *Bit)
            {
                ++Ait;
                prev = *Bit;
                continue;
            }
            if (prev != *Bit)
                break;
            prev = *Bit;
        }
        if (Bit == B.end() && Ait == A.end())
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}
