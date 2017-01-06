#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct point{
    int x,y;
}point;
int cmp(const void *A, const void *B)
{
    if(((point*)A)->x>((point*)B)->x) return 1;
    else if(((point*)A)->x==((point*)B)->x && ((point*)A)->y>((point*)B)->y) return 1;
    return -1;
}
int next_point(point* data, int cur, int size)
{
    int fir=cur+1, sec=cur+2;
    while(sec<size)
    {
        int vecx1=(data+fir)->x-(data+cur)->x;
        int vecy1=(data+fir)->y-(data+cur)->y;
        int vecx2=(data+sec)->x-(data+cur)->x;
        int vecy2=(data+sec)->y-(data+cur)->y;
        if((vecx1*vecy2-vecy1*vecx2)<0)
        {
            fir=sec;
        }
        ++sec;
    }
    return fir;
}
int pre_point(point* data, int cur)
{
    int fir=cur-1, sec=cur-2;
    while(sec>=0)
    {
        int vecx1=(data+fir)->x-(data+cur)->x;
        int vecy1=(data+fir)->y-(data+cur)->y;
        int vecx2=(data+sec)->x-(data+cur)->x;
        int vecy2=(data+sec)->y-(data+cur)->y;
        if((vecx1*vecy2-vecy1*vecx2)<0)
        {
            fir=sec;
        }
        --sec;
    }
    return fir;
}
int main()
{
    int Max=1, size=0;
    point* data=malloc(sizeof(data));
    int x, y;
    while(scanf("%d %d\n", &x, &y)==2)
    {
        if(Max==size)
        {
            Max<<=1;
            point* newdata=malloc(sizeof(data)*Max);
            memcpy(newdata, data, sizeof(data)*size);
            free(data);
            data=newdata;
        }
        (data+size)->x=x;
        (data+size)->y=y;
        ++size;
    }
    if(size==1)
    {
        printf("%d %d\n", data->x, data->y);
        return 0;
    }
    qsort(data, size, sizeof(point), cmp);
    int cur=0;
    while(cur<size)
    {
        printf("%d %d\n", (data+cur)->x, (data+cur)->y);
        cur=next_point(data, cur, size);
    }
    --cur;
    while(cur=pre_point(data, cur))
    {
        if(cur==0)
            break;
        printf("%d %d\n", (data+cur)->x, (data+cur)->y);
    }
    return 0;
}
