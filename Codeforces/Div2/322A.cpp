#include <iostream>

using namespace std;

int main()
{
    int total, abs, red, blue;
    while(cin>>red>>blue)
    {
        total=(red+blue)/2;
        abs=(red-blue)/2;
        if(abs<0)
            abs=-abs;
        cout<<total-abs<<" "<<abs<<"\n";
    }
    return 0;
}