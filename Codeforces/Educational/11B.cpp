#include <bits/stdc++.h>
using namespace std;
int main()
{
    int rows, passengers;
    cin>>rows>>passengers;
    vector<int> seat[rows];
    for(int x=0; x<rows; x++)
    {
        seat[x].assign(4,0);
    }
    int curp=0;
    for(int x=0; x<rows; x++)
    {
        ++curp;
        seat[x][0]=curp;
        if(curp==passengers)
        break;
        ++curp;
        seat[x][3]=curp;
        if(curp==passengers)
        break;
    }
    for(int x=0; x<rows; x++)
    {
        if(curp==passengers)
        break;
        ++curp;
        seat[x][1]=curp;
        if(curp==passengers)
        break;
        ++curp;
        seat[x][2]=curp;
        if(curp==passengers)
        break;
    }
    bool start=true;
    for(int x=0; x<rows; x++)
    {
        for(int y=1; y>=0; y--)
        {
            if(seat[x][y]==0)
                continue;
            if(!start)
                cout<<" ";
            start=false;
            cout<<seat[x][y];
        }
        for(int y=2; y<4; y++)
        {
            if(seat[x][y]==0)
                continue;
            cout<<" "<<seat[x][y];
        }
    }
    return 0;
}
