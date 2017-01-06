#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 0x7f7f7f7f
typedef struct node{
    int freq;
    char val;
    struct node* left;
    struct node* right;
}node;
typedef struct ans{
    char value;
    char* code;
    int freq;
}ans;
void swap(node* A, node* B)
{
    node* temp=malloc(sizeof(node));
    *temp=*A;
    *A=*B;
    *B=*temp;
    return;
}
int cmp(const void* A, const void* B)
{
    if( ((node*)A)->freq<((node*)B)->freq )
        return -1;
    return 1;
}
int cmp2(const void* A, const void* B)
{
    if( ((ans*)A)->freq<((ans*)B)->freq )
        return -1;
    return 1;
}

void TopDown(node* data, int idx, const int size)
{
    int left=idx*2+1, right=idx*2+2;
    if((data+left)->freq<(data+right)->freq)
    {
        if(left<size && (data+left)->freq<(data+idx)->freq)
        {
            swap(data+left, data+idx);
            TopDown(data, left, size);
        }
    }
    else if(right<size && (data+right)->freq<(data+idx)->freq)
    {
        swap(data+right, data+idx);
        TopDown(data, right, size);
    }
    return;
}

void dfs(node* data, char* stack, int stackptr, ans* final, int* cnt)
{
    if(data->val!=0x7f)
    {
        (final+*cnt)->value=data->val;
        (final+*cnt)->freq=data->freq;
        (final+*cnt)->code=malloc(sizeof(char)*(stackptr+1));
        for(int x=0; x<=stackptr; x++)
        {
            *((final+*cnt)->code+x)=*(stack+x);
        }
        *((final+*cnt)->code+stackptr+1)='\0';
        ++(*cnt);
        return;
    }
    ++stackptr;
    *(stack+stackptr)='0';
    dfs(data->left, stack, stackptr, final, cnt);
    *(stack+stackptr)='1';
    dfs(data->right, stack, stackptr, final, cnt);
    return;
}
int main()
{
    int cases;
    scanf("%d\n", &cases);
    while(cases--)
    {
        char* inp=malloc(sizeof(char)*500);
        fgets(inp, 500, stdin);
        char* tok=strtok(inp," ");
        node* data=malloc(sizeof(node));
        int Max=1, size=0;
        while(tok!=NULL)
        {
            if(size==Max/2)
            {
                Max<<=1;
                node* newdata=malloc(sizeof(node)*Max);
                memset(newdata, 0x7f, sizeof(node)*Max);
                memcpy(newdata, data, sizeof(node)*size);
                free(data);
                data=newdata;
            }
            (data+size)->val=*tok;
            ++size;
            tok=strtok(NULL," ");
        }
        int inpn;
        for(int x=0; x<size; x++)
        {
            scanf("%d", &inpn);
            (data+x)->freq=inpn;
        }
        scanf("%d\n", &inpn);
        qsort(data, size, sizeof(node), cmp);
        while((data+1)->freq!=MAX || (data+2)->freq!=MAX)
        {
            node* node1=malloc(sizeof(node));
            node* node2=malloc(sizeof(node));
            *node1=*data;
            memset(data, 0x7f, sizeof(node));
            TopDown(data, 0, Max);

            *node2=*data;
            node* Newnode=malloc(sizeof(node));
            memset(Newnode, 0x7f, sizeof(node));
            Newnode->freq=node1->freq+node2->freq;
            if(node1->freq>node2->freq)
            {
                Newnode->left=node1;
                Newnode->right=node2;
            }
            else
            {
                Newnode->left=node2;
                Newnode->right=node1;
            }
            *data=*Newnode;

            TopDown(data, 0, Max);
        }
        ans* final=malloc(sizeof(ans)*size);
        char* stack=malloc(sizeof(char)*Max);
        int* cnt=malloc(sizeof(int));
        *cnt=0;
        dfs(data, stack, -1, final, cnt);
        qsort(final, size, sizeof(ans), cmp2);
        for(int x=0 ; x<size; x++)
        {
            printf("%c %s\n", (final+x)->value, (final+x)->code);
        }
    }
    return 0;
}
