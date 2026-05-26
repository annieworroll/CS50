// Create a mario half pyramid
#include <cs50.h>
#include <stdio.h>

void draw_row(int row_height, int row_num);
void draw_pyramid(int height);

int main()
{
    int height = 0;
    do{
        height = get_int("How tall? ");
    }while(height <= 0);

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
    // First half
    int j = 0;
    for(; j < row_height - row_num; ++j){
        printf(" ");
    }
    for(; j < row_height; ++j){
        printf("#");
    }

    //gap
    printf("  ");

    // second half
    for(int i = 0; i < row_num; ++i){
        printf("#");     
    }

    // go to next line
    printf("\n");
}