#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        int columns, buffer, ignore;
        cin >> columns >> buffer >> ignore;
        int current, next;
        cin >> current;
        bool no = false;
        while (--columns)
        {
            cin >> next;
            buffer += current - max(next - ignore, 0);
            if (buffer < 0)
                no = true;
            current = next;
        }
        if (no)
            cout << "NO\n";
        else
            cout << "YES\n";
    }

    return 0;
}
