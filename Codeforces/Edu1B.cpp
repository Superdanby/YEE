#include <iostream>

using namespace std;

int main()
{
    string input;
    cin>>input;
    int cases;
    cin>>cases;
    while(cases--)
    {
        int fro, bac, times;
        cin>>fro>>bac>>times;
        times=times%(bac-fro+1);
        string temp=input;
        for(int y=0,x=times; x>=0; y++,x--)
        {
            temp[x]=input[bac-y];
        }

        for(int x=bac-1; x>fro-3+times; x--)
        {
            input[x]=input[x-times];
//            cout<<x<<","<<input<<" "<<"fro-3+times"<<fro-3+times<<" ";
        }
        for(int x=fro-1,y=0; x<fro-1+times; y++, x++)
        {
//            cout<<x<<","<<y<<" "<<"fro-1+times"<<fro-1+times<<" ";
            input[x]=temp[y];
        }
//            cout<<input;
    }
    cout<<input;
    return 0;
}
