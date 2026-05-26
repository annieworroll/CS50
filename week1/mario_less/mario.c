// Create a mario half pyramid
#include <cs50.h>
#include <stdio.h>

void draw_row(int row_height, int row_num);
void draw_pyramid(int height);

int main()
{
    int height = get_int("How tall? ");
    draw_pyramid(height);

    return 0;
}

void draw_pyramid(int height)
{
    for(int n = 0; n < height; ++n){
        draw_row(height, n + 1);
    }
}

void draw_row(int row_height, int row_num)
{
    int j = 0;
    for(; j < row_height - row_num; ++j){
        printf(" ");
    }
    for(; j < row_height; ++j){
        printf("#");
    }
    printf("\n");
}