#include <bits/stdc++.h>
using namespace std;
struct cargo{
    int idx, num;
};
bool cmp(const cargo &A, const cargo &B)
{
    return A.num<B.num;
}
int main()
{
    string inpf, inps;
    while(getline(cin, inpf))
    {
        getline(cin, inps);
        cin.ignore();
        istringstream iss(inpf);
        vector<cargo> First;
        cargo tok;
        tok.idx=0;
        tok.num=0;
        First.push_back(tok);
        while(iss>>tok.num)
        {
            ++tok.idx;
//            cout<<tok.idx<<"tok"<<tok.num<<"\n";
            First.push_back(tok);
        }
        sort(First.begin(), First.end(), cmp);
        istringstream isss(inps);
        int toks;
        isss>>toks;
        vector<bool> check(First.size()+1,0);
        check[First[toks].idx]=1;
        do{
//            cout<<toks<<"i"<<First[toks].num<<"n"<<First[toks].idx<<" ";
            if(check[First[toks].idx])
            {
                check[First[toks].idx+1]=1;
                check[First[toks].idx-1]=1;
            }
            else
            {
                cout<<"No\n\n";
                break;
            }
        }while(isss>>toks);
        if(!check[First[toks].idx])
            continue;
        cout<<"Yes\n\n";
    }
    return 0;
}
