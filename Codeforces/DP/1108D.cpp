#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int length, cnt = 1, ans = 0;
    cin >> length;
    char prev = '0';
    string str;
    cin >> str;
    str.push_back('A');
    unordered_map<char, short> dict({{'R', 0}, {'G', 0}, {'B', 0}, {'A', 1}});
    for (size_t i = 0; i < str.length(); ++i)
    {
        if (prev == str[i])
        {
            ++cnt;
            if (cnt % 2 == 0)
            {
                ++dict[str[i - 1]];
                ++dict[str[i + 1]];
                for (auto && [first, second]: dict)
                {
                    if (second == 0)
                        str[i] = first;
                    else
                        second = 0;
                }
                dict['A'] = 1;
            }
        }
        else
        {
            ans += cnt / 2;
            cnt = 1;
            prev = str[i];
        }
    }
    cout << ans << "\n";
    str.pop_back();
    cout << str << "\n";

    return 0;
}
