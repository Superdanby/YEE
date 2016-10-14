#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Size 5
int main()
{
    int** Matrix=malloc(Size*sizeof(int*));
    int** result=malloc(Size*sizeof(int*));
    for(int x=0; x<Size; x++)
    {
        Matrix[x]=malloc(Size*sizeof(int));
        result[x]=malloc(Size*sizeof(int));
    }
    for(int x=0; x<Size; x++)
    {
        for(int y=0; y<Size; y++)
        {
            scanf("%d", &Matrix[x][y]);
//            result[x][y]=Matrix[x][y];
            //printf("%d %d\n", Matrix[x][y],x);
        }
    }
    char L;
    while(scanf("%c", &L)==1)
    {
        if(L=='L')
        {
            int i=0;
            for(int x=Size-1; x>=0; x--)
            {
                int j=0;
                for(int y=0; y<Size; y++)
                {
                    result[i][j]=Matrix[y][x];
                    ++j;
                }
                ++i;
            }
            int** temp=result;
            result=Matrix;
            Matrix=temp;
        }
    }
    for(int x=0; x<Size; x++)
    {
        for(int y=0, space=0; y<Size; y++)
        {
            if(space)
                printf(" ");
            else
                space=1;
            printf("%d", Matrix[x][y]);
        }
        printf("\n");
    }
    return 0;
}
