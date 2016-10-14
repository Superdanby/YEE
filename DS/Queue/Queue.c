#include <stdio.h>
#include <stdlib.h>
#define ubound 10
typedef struct node{
    int num;
    struct node* next;
} node;
int main()
{
    int cnt=0;
    int choice;
    node* head=malloc(sizeof(*head));
    node* cur=malloc(sizeof(*cur));
    head->num=0;
    cur->next=head;
    int ininum, inp;
    scanf("%d", &ininum);
    for(int x=0; x<ininum; x++)
    {
        scanf("%d", &inp);
        if(cnt>=ubound)
            continue;
        node* iniNew=malloc(sizeof(node));
        iniNew->num=inp;
        cur->next->next=iniNew;
        cur->next=cur->next->next;
        ++cnt;
    }
    while(scanf("%d", &choice)==1)
    {
        switch (choice){
            case 1:
            {
                scanf("%d", &inp);
                if(cnt==ubound)
                    break;
                node* New=malloc(sizeof(node));
                New->num=inp;
                cur->next->next=New;
                cur->next=cur->next->next;
//                printf("%d %d\n", inp, head->next->num);
                ++cnt;
                break;
            }
            case 2:
            {
                if(!cnt)
                    break;
                else if(cur->next==head->next)
                {
                    free(head->next);
                    cur->next=head;
                    --cnt;
                    break;
                }
                node* dptr=malloc(sizeof(node));
                dptr=head->next;
                head->next=head->next->next;
                free(dptr);
                --cnt;
                break;
            }
        }
//        printf("%dcnt\n", cnt);
    }
    if(cur->next==head)
        return 0;
    node* visit=malloc(sizeof(node));
    *visit=*head;
    while(visit->next!=cur->next)
    {
        printf("%d ", visit->next->num);
        visit->next=visit->next->next;
    }
    printf("%d\n", visit->next->num);
    return 0;
}
