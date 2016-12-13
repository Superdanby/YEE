#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ascii 128
#define Max 100
typedef struct node{
//    int fromr;
//    int froml;
    int left;
    int right;
}node;
node Tree[ascii];
void dfs(int cur)
{
//    printf("check%c", (char)cur);
    if(Tree[cur].left!=-1)
        dfs(Tree[cur].left);
    if(Tree[cur].right!=-1)
        dfs(Tree[cur].right);
    printf("%c", (char)cur);
    return;
}
int main()
{
    int cases;
    scanf("%d", &cases);
    while(cases--)
    {
        int Inidx[ascii];
        memset(Inidx,-1,sizeof(Inidx));
        char*Prefix=malloc(sizeof(char));
        char*Infix=malloc(sizeof(char));
        scanf("%s", Prefix);
        scanf("%s", Infix);
        int length=strlen(Prefix);
//        printf("%dlength\n", length);
        for(int x=0; x<length; x++)
        {
            Inidx[(int)Infix[x]]=x;
        }
//        node Tree[ascii];
        memset(Tree, -1, sizeof(Tree));
//        Tree[(int)Prefix[0]].froml=(int)Prefix[0];
//        Tree[(int)Prefix[0]].fromr=(int)Prefix[0];
        for(int x=1; x<length; x++)
        {
//            printf("%d\n", x);
            int cur=(int)Prefix[0];
            while((Tree[cur].left!=-1 && Inidx[(int)Prefix[x]]<Inidx[cur]) || (Tree[cur].right!=-1 && Inidx[(int)Prefix[x]]>Inidx[cur]))
            {
//                printf("%c", (char)cur);
                if(Inidx[(int)Prefix[x]]<Inidx[cur])
                    cur=Tree[cur].left;
                else
                    cur=Tree[cur].right;
            }
//            printf("path %cNew\n", Prefix[x]);
            if(Inidx[(int)Prefix[x]]<Inidx[cur])
            {
                Tree[cur].left=(int)Prefix[x];
//                printf("%cleft\n", (char)Tree[cur].left);
//                Tree[(int)Prefix[x]].froml=cur;
            }
            else
            {
                Tree[cur].right=(int)Prefix[x];
//                Tree[(int)Prefix[x]].fromr=cur;
            }
        }
//        printf("%d\n", (int)Prefix[0]);
        dfs((int)Prefix[0]);
        printf("\n");
    }
    return 0;
}
