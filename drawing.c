#include <stdio.h>
#include "foc_su22.h"

#define H 500 
#define W 500 

void erase(int arr[W][H])
{
    for (int i =0; i < W; i++)
    {
        for (int j=0; j< H; j++)
        {
            arr[i][j] = 255;
        }
    }
}

void draw_square( int arr[H][W], int x, int y , int h,int w, int color)
{
    int x2 = x + h;
    int y2 = y + w; 
    for (int i =0; i < H; i++) // height
    {
        for (int j=0; j< W; j++) // width 
        {
            if ( i >y && i <= y2 && j > x && j <= x2 )
                arr[i][j] = color;
        }
    }
}

void draw_triangle(int arr[H][W], int x, int y, int base, int height, int color)
{    
    for (int i=0; i < height; i++)
    {
        for (int k = base - i; k>0;k--)
            arr[y-i][x+k+i] = color;
        for (int l = i; l>0; l--)
            arr[y-i][x+(base-i)+l] = 255;
    }
}

int main()
{
    int arr[H][W] = {0};
    erase(arr);
    draw_square(arr , 100, 200 , 200, 200, 125);
    draw_triangle(arr, 100,200, 190 , 100 , 25);
    draw_square(arr, 290 , 80 , 10, 120, 100);
    //draw_square(arr,150,250, 100 ,150 , 200);
    showArray(H,W, arr);
    return 0;
}

