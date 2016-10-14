/*
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Msize 110
typedef struct cargo{
    int idx, num;
} cargo;
int cmp(const void *A, const void *B)
{
    cargo *ptr1= (cargo*)A;
    cargo *ptr2= (cargo*)B;
    if(ptr1->num>ptr2->num)
        return 1;
    else
        return 0;
}
int main()
{
    char inpf[Msize], inps[Msize], Ignore[Msize];
    while(fgets(inpf, sizeof(inpf), stdin))
    {
        fgets(inps, sizeof(inps), stdin);
        fgets(Ignore, sizeof(Ignore), stdin);
        char *start=inpf;
        start=strtok(start, " ");
        cargo First[Msize];
        cargo tok;
        tok.idx=0;
        tok.num=0;
        First[0]=tok;
        while(start!=NULL)
        {
            ++tok.idx;
            sscanf (start, "%d", &tok.num);
            First[tok.idx]=tok;
            start=strtok(NULL, " ");
        }
        qsort(First, tok.idx+1, sizeof(cargo), cmp);
        start=inps;
        start=strtok(start, " ");
        int toks;
        sscanf (start, "%d", &toks);
        int check[tok.idx+2];
        memset(check,0,sizeof(check));
        check[First[toks].idx]=1;
        do{
            if(check[First[toks].idx])
            {
                check[First[toks].idx+1]=1;
                check[First[toks].idx-1]=1;
            }
            else
            {
                printf("No\n\n");
                break;
            }
            start=strtok(NULL, " ");
            if(start!=NULL)
                sscanf(start, "%d", &toks);
        }while(start!=NULL);
        if(!check[First[toks].idx])
            continue;
        printf("Yes\n\n");
    }
    return 0;
}
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Msize 10001
int main()
{
    char inp[Msize];
    while(fgets(inp, sizeof(inp), stdin))
    {
        char* start=inp;
        start=strtok(start, " ");
        int Queue[Msize];
        memset(Queue,0,sizeof(Queue));
        int Qidx=0;
        while(start!=NULL)
        {
            sscanf(start, "%d", &Queue[Qidx]);
            ++Qidx;
            start=strtok(NULL, " ");
        }
        start=inp;
        start=strtok(start, " ");
        fgets(inp, sizeof(inp), stdin);
        while(start!=NULL)
        {
            sscanf(start, "%d", &Queue[Qidx]);
            ++Qidx;
            start=strtok(NULL, " ");
        }
        fgets(inp, sizeof(inp), stdin);
        int Queryidx=Qidx/2;
        int End=Qidx;
        int Mid=Queryidx;
        Qidx=0;
        int Stack[Msize];
        memset(Stack, 0, sizeof(Stack));
        int Sidx=1;
        while(Queryidx<End && Qidx<=Mid)
        {
    //        printf("%d:%d %d:%d %d:%d\n", Sidx, Stack[Sidx-1], Qidx, Queue[Qidx], Queryidx, Queue[Queryidx]);
            if(Stack[Sidx-1]==Queue[Queryidx])
            {
                ++Queryidx;
                --Sidx;
            }
            else if(Queue[Qidx]==Queue[Queryidx])
            {
                ++Queryidx;
                ++Qidx;
            }
            else
            {
                Stack[Sidx]=Queue[Qidx];
                ++Sidx;
                ++Qidx;
            }
        }
        if(Queryidx==End)
            printf("Yes\n");
        else
            printf("No\n");
    }

    return 0;
}
