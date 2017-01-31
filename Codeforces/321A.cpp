#include <iostream>

using namespace std;

int main()
{
    int total,t,final=1,ansb=0;
    cin>>total;
    t=total;
    int A[total+1];
    A[0]=0;
    int x;
    for(;total>0;total--)
    {
        cin>>x;
        A[total]=x;
      //  cout<<A[total-1]<<"\n";
    }
    total=t;
    for(;total>0;total--)
    {
        int y;
        //cout<<"total"<<A[total]<<" "<<A[total-1];
        if(A[total-1]>=A[total])
        {
            final=final+1;
      //      y=11;
      //      cout<<y;
        }
        else
        {
            ansb=max(ansb,final);
            //cout<<"ansb"<<ansb<<"\n";
            final=1;
      //      y=10;
      //      cout<<y;
        }
            ansb=max(ansb,final);
         //   cout<<"final"<<final<<"\n";
         //   cout<<"ansb"<<ansb<<"\n";
    }
    cout<<ansb;
    return 0;
}