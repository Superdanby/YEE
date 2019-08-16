#include <bits/stdc++.h>

using namespace std;

constexpr int MAX = 0x7f7f7f7f;

int main(int argc, char const *argv[]) {
    int cases;
    cin >> cases;
    while (cases--)
    {
        int rows, columns;
        cin >> rows >> columns;
        vector<vector<int>> graph(rows, vector<int>(columns, 0));
        vector<int> row(rows, 0), column(columns, 0);
        char inp;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                cin >> inp;
                if (inp == '.')
                {
                    ++row[i];
                    graph[i][j] = -1;
                }
            }
        }
        for (int j = 0; j < columns; ++j)
        {
            for (int i = 0; i < rows; ++i)
            {
                if (graph[i][j] == -1)
                    ++column[j];
            }
        }
        int ans = MAX;
        for (int i = 0; i < rows; ++i)
        {
            for (int j = 0; j < columns; ++j)
            {
                int total = graph[i][j] + row[i] + column[j];
                ans = total < ans ? total : ans;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}
