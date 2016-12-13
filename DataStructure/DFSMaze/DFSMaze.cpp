#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
int startf, starts, goalf, goals;
typedef struct node{
    int fir, sec;
}node;
int edge;
int Map[101][101], constMap[101][101];
void gotoxy(int x,int y)
{
    #ifdef __linux__
        printf("%c[%d;%df",0x1B,y+1,x+1);
    #elif _WIN32
        COORD coord;
        coord.X = x;
        coord.Y = y;
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
    #endif
    fflush(stdout);
}
void Print()
{
    for(int x=0; x<edge; x++)
    {
        for(int y=0; y<edge-1; y++)
        {
            if(constMap[x][y]==2)
                printf("$");
            else if(constMap[x][y])
                printf("#");
            else
                printf(" ");
        }
        if(constMap[x][edge-1]==2)
            printf("$\n");
        else if(constMap[x][edge-1])
            printf("#\n");
        else
            printf(" \n");
    }
    printf("\n");
}
int main()
{
    scanf("%d",&edge);
    scanf("%d %d %d %d", &starts, &startf, &goals, &goalf);
    for(int x=0; x<edge; x++)
    {
        for(int y=0; y<edge; y++)
        {
            scanf("%d", &Map[x][y]);
            constMap[x][y]=Map[x][y];
        }
    }
    int coins=0;
    node stack[2*edge*edge];
    int stackptr=0, pref=startf, pres=starts, presym=Map[startf][starts];
    stack[0].fir=startf, stack[0].sec=starts;
    system("clear");
    Print();
    clock_t clock1=clock();
    time_t time1=time(0);
    while(difftime(time(0), time1)<1.0)
    {
        //printf("%f\n",difftime(time(0), time1));
    }
    clock_t interval=clock()-clock1;
    while(stackptr>=0)
    {
        int fir=stack[stackptr].fir;
        int sec=stack[stackptr].sec;
        gotoxy(pres,pref);
        if(!presym)
            printf(" ");
        else if(presym==1)
            printf("#");
        clock1=clock();
        while(clock()-clock1<interval*1/8)
        {}
        gotoxy(sec,fir);
        printf("@");
        pref=fir;
        pres=sec;
        presym=constMap[fir][sec];
        --stackptr;
//        printf("%d %d %d %d\n\n", fir, sec, goalf, goals);
        if(Map[fir][sec]==1 || Map[fir][sec]==3)
            continue;
        if(Map[fir][sec]==2)
        {
            ++coins;
            Map[fir][sec]=0;
            constMap[fir][sec]=0;
            presym=0;
            gotoxy(0, edge);
            printf("Coins picked up:%d\n", coins);
        }
        Map[fir][sec]=3;
        if(fir==goalf && sec==goals)
        {
            break;
        }
        ++stackptr;
        stack[stackptr].fir=fir;stack[stackptr].sec=sec-1;
        ++stackptr;
        stack[stackptr].fir=fir+1;stack[stackptr].sec=sec;
        ++stackptr;
        stack[stackptr].fir=fir;stack[stackptr].sec=sec+1;
        ++stackptr;
        stack[stackptr].fir=fir-1;stack[stackptr].sec=sec;
    }
    return 0;
}
