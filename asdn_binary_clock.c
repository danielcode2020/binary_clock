#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <unistd.h>

int display[6][6];

int main()
{
    while (1)
    {
        time_t now = time(NULL);
        struct tm *tm_struct = localtime(&now);
        int hour = tm_struct->tm_hour;
        int min = tm_struct->tm_min;
        int sec = tm_struct->tm_sec;
        printf("%d %d %d ", hour, min, sec);
        ttb(hour,0);
        ttb(min,2);
        ttb(sec,4);
        print_clock();
        sleep(1);
        initialize_clock();
        system("clear");
    }
}

// time to binary and changing the matrix of console
// for hour column = 0, min column = 2, sec column = 4

void ttb( int i, int column)
{
    int m = i % 10;
    int n = i / 10;
    change_column(n,column);
    change_column(m,column+1);

}

void change_column(int n, int column)
{
    if (n==1)
    {
        display[5][column]  = 1; // 1
    }
    if (n==2)
    {
        display[4][column] = 1; // 2
    }
    if (n==3)
    {
        display[5][column] = 1;
        display[4][column] = 1;
    }
    if (n==4)
    {
        display[3][column] = 1; // 4
    }
    if (n==5)
    {
        display[3][column] = 1;
        display[5][column] = 1;
    }
    if (n==6)
    {
        display[3][column] = 1;
        display[4][column] = 1;
    }
    if (n==7)
    {
        display[3][column] = 1;
        display[4][column] = 1;
        display[5][column] = 1;
    }
    if (n==8)
    {
        display[2][column] = 1; // 8
    }
    if (n==9)
    {
        display[2][column] = 1;
        display[5][column] = 1;
    }

}

void initialize_clock()
{

for (int i=0;i<6;i++){
        for (int j=0;j<6;j++){
            display[i][j]=0;
        }
    }
}

void print_clock()
{
    printf("\n");
    for(int i=0; i<6; i++) {
      for(int j=0;j<6;j++) {
            printf("%d  ", display[i][j]);
        }
        printf("\n");
    }
}

