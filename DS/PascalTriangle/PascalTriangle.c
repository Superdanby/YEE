#include <stdio.h>
#include <stdlib.h>
typedef struct node{
    int value;
    struct node* next;
} node;
void solve(int level)
{
    node* pascal=malloc((level+1)*sizeof(*pascal));
    printf("1\n");
    node* inib=malloc(sizeof(*inib));
    node* terminate=malloc(sizeof(*terminate));
    inib->value=1;
    inib->next=terminate;
    (pascal)->next=terminate;
    (pascal)->value=1;
    int Max=1;
    for(int x=1; x<level; x++)
    {
        (pascal+x)->value=1;
        node* visit=&pascal[x-1];
        node* construct=&pascal[x];
        printf("%d ", construct->value);
        while(visit->next!=terminate)
        {
            node* temp=malloc(sizeof(*temp));
            temp->value=visit->value+visit->next->value;
            Max=(temp->value>Max?temp->value:Max);
            construct->next=temp;
            visit=visit->next;
            construct=construct->next;
            printf("%d ", construct->value);
        }
        construct->next=inib;
        printf("%d\n", inib->value);
    }
    printf("%d\n", Max);
    return;
}
int main()
{
    int level;
    scanf("%d", &level);
    solve(level);
    return 0;
}
