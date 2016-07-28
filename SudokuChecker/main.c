#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sudoku.h"

int main(int argc, char *argv)
{
    int n;
    if(argc == 1) {
        n = 9;
    }
    else if(argc == 2) {
        n = *argv;
    }
    FILE * fp = fopen("sudoku_1.txt","r");

    int grid[n][n];
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            char s[] = "0";
            fscanf(fp, " %c", &s[0]);
            grid[i][j] = atoi(s);
        }
    }

    printf("Verdict: %s", is_solved(grid, n));

    /*
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++) {
            printf("%d", grid[i][j]);
        }
        printf("\n");
    }
    */

    return 0;
}
