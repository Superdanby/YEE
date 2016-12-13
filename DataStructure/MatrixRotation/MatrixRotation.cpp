#include <bits/stdc++.h>
using namespace std;
void rotate(vector<vector<int>> &Matrix)
{
    vector<vector<int>> temp(Matrix);
    int i=0;
    for(int x=Matrix.size()-1; x>=0; x--)
    {
        int j=0;
        for(int y=0, space=0; y<Matrix.size(); y++)
        {
            if(space)
                cout<<" ";
            cout<<temp[y][x];
            Matrix[i][j]=temp[y][x];
            ++j, ++space;
        }
        cout<<"\n";
        ++i;
    }
}
int main()
{
    string row;
    int colcnt=0;
    vector<vector<int>> Matrix;
    vector<int> Newcol;
    while(getline(cin, row))
    {
        if(row=="L")
        {
            rotate(Matrix);
            continue;
        }
        else if(row=="")
            break;
        Matrix.push_back(Newcol);
        istringstream iss(row);
        int inp;
        while(iss>>inp)
        {
//            cout<<inp<<" ";
            Matrix[colcnt].push_back(inp);
        }
        ++colcnt;
    }
    return 0;
}
