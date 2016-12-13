#include <bits/stdc++.h>
using namespace std;
struct node{
    int idx, num;
    node* next;
};
int main()
{
    int choice;
    node* head=new node;
    node* cur=new node;
    head->num=0;
    cur->next=head;
    while(scanf("%d", &choice))
    {
        switch (choice){
            case 1:
            {
                int inp;
                scanf("%d", &inp);
                node* New=new node;
                New->idx=cur->next->idx+1;
                New->num=inp;
                cur->next->next=New;
                cur->next=cur->next->next;
                break;
            }
            case 2:
            {
                int Ignore;
                scanf("%d", &Ignore);
                head->next=head->next->next;
                break;
            }
            case 3:
                return 0;
        }
        node* visit=new node;
        *visit=*head;
        while(visit->next!=cur->next)
        {
            printf("%d ", visit->next->num);
            visit->next=visit->next->next;
        }
        printf("%d\n", visit->next->num);
        printf("%d\n", head->next->idx);
        printf("%d\n\n", cur->next->idx);
    }
    return 0;
}
