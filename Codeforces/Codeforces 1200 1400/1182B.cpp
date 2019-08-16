#include <bits/stdc++.h>

using namespace std;

int main(int argc, char const *argv[]) {
    int rows, columns;
    cin >> rows >> columns;
    int upx = -1, upy = -1, leftx = -1, lefty = -1, cnt = 0;
    vector<vector<char>> graph(rows, vector<char>(columns));
    char inp;
    bool ans = false;
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            cin >> inp;
            graph[i][j] = inp;
            if (inp == '*')
            {
                if (upx == -1)
                    upx = j, upy = i;
                else if (leftx == -1 && upx != j)
                    leftx = j, lefty = i;
                ++cnt;
            }
        }
    }
    if (upx > leftx && upy < lefty)
    {
        int downy = upy;
        for (; downy < rows; ++downy)
        {
            if (graph[downy][upx] == '.')
                break;
            else
                --cnt;
        }
        --downy;
        if (downy > lefty)
        {
            int rightx = leftx;
            for (; rightx < columns; ++rightx)
            {
                if (graph[lefty][rightx] == '.')
                    break;
                else
                    --cnt;
            }
            --rightx;
            if (rightx > upx && cnt == -1)
                ans = true;
        }
    }
    if (ans)
        cout << "YES\n";
    else
        cout << "NO\n";
    return 0;
}
