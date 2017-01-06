#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NegINF (int)0x88888888 //-2004318072
#define PosINF (int)0x7f7f7f7f // 2139062143
//#define MAX //Max Heap
#define MIN //Min Heap
void swap(int* A, int* B)
{//Swap A and B
    int temp=*A;
    *A=*B;
    *B=temp;
    return;
}
void BottomUp(int* data, int idx, const int size)
{//Sort upon input, O(log(n));
    int left=idx*2+1, right=idx*2+2;
    #ifdef MAX
        if(left<size && *(data+left)>*(data+idx))
            swap(data+left, data+idx);
        if(right<size && *(data+right)>*(data+idx))
            swap(data+right, data+idx);
    #elif defined MIN
        if(left<size && *(data+left)<*(data+idx))
            swap(data+left, data+idx);
        if(right<size && *(data+right)<*(data+idx))
            swap(data+right, data+idx);
    #endif
    if(idx>0)
        BottomUp(data, (idx-1)/2, size);
    return;
}
void TopDown(int* data, int idx, const int size)
{//Sort upon output, O(log(n))
    int left=idx*2+1, right=idx*2+2;
    #ifdef MAX
        if(*(data+left)>*(data+right))
        {
            if(left<size && *(data+left)>*(data+idx))
            {
                swap(data+left, data+idx);
                TopDown(data, left, size);
            }
        }
        else if(right<size && *(data+right)>*(data+idx))
        {
            swap(data+right, data+idx);
            TopDown(data, right, size);
        }
    #elif defined MIN
        if(*(data+left)<*(data+right))
        {
            if(left<size && *(data+left)<*(data+idx))
            {
                swap(data+left, data+idx);
                TopDown(data, left, size);
            }
        }
        else if(right<size && *(data+right)<*(data+idx))
        {
            swap(data+right, data+idx);
            TopDown(data, right, size);
        }
    #endif
    return;
}
int Replace(int* data, int Max, int replace)
{
    int pop=*data;
    //Replace root with replace
    *data=replace;
    //Sort from root
    TopDown(data, 0, Max);
    return pop;
}
int main()
{
    int* data=malloc(sizeof(int));//data=dyanmic array
    int Max=1, size=0, inp;//Max=size of the current heap tree; size=node count
    while(scanf("%d", &inp)==1)
    {//Input
        if(size==Max)
        {//if data is full, double the size of it
            Max<<=1;
            int* newdata=malloc(sizeof(int)*Max);
            #ifdef MAX
                memset(newdata, 0x88, sizeof(int)*Max);
            #elif defined MIN
                memset(newdata, 0x7f, sizeof(int)*Max);
            #endif
            memcpy(newdata, data, sizeof(int)*size);
            free(data);
            data=newdata;
        }

        //Input
        *(data+size)=inp;
        ++size;

        //Sort
        BottomUp(data, (size-2)/2, size); //(size-2)/2 is the index of the parent node of the current input
    }
    while(size--)
    {//Output
        #ifdef MAX
            printf("%d\n", Replace(data, Max, NegINF));
        #elif defined MIN
            printf("%d\n", Replace(data, Max, PosINF));
        #endif
    }
    return 0;
}
