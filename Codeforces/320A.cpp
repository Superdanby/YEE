#include <iostream>
using namespace std;

int cal(int x)
{
    int temp,z = 0;
    temp=x;
    while(temp)
    {
        int y = -1;
        while(x!=0)
        {
            y=y+1;
            x=x/2;
      //      cout<<"y"<<y<<"\n";
        }
        int w=1;
        for(;y>0;y--)
           {
              w=w*2;
           }
        temp=temp-w;
        x=temp;
      //  cout<<"temp"<<temp<<"\n";
        z=z+1;
     //   cout<<"z"<<z<<"\n";
    }
    return z;
}
int main()
{
int in,out;
cin>>in;
out=cal(in);
cout<<out;
}
