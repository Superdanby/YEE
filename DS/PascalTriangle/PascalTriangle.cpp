#include <bits/stdc++.h>
using namespace std;
struct node{
    int value;
    node* next;
};
void solve(int level)
{
    node* pascal=new node[level+1];
//    memset(pascal, 0, sizeof(pascal));
    printf("1\n1 1\n");
    node* inib=new node;
    node* terminate=new node;
    inib->value=1;
    inib->next=terminate;
//    cout<<pascal<<" "<<pascal->next<<"\n";
    (pascal+1)->next=inib;
//    cout<<"p\n";
    (pascal+1)->value=1;
    if(level==1)
        return;
    for(int x=2; x<=level; x++)
    {
//        cout<<x<<"x\n";
        (pascal+x)->value=1;
        node* visit=&pascal[x-1];
        node* construct=&pascal[x];
        printf("%d ", construct->value);
        while(visit->next!=terminate)
        {
            node* temp=new node;
            temp->value=visit->value+visit->next->value;
//            cout<<temp->value<<"t ";
            construct->next=temp;
            visit=visit->next;
            construct=construct->next;
            printf("%d ", construct->value);
        }
        construct->next=inib;
        printf("%d\n", inib->value);
    }
}
int main()
{
    int level;
    scanf("%d", &level);
    solve(level);
    return 0;
}
