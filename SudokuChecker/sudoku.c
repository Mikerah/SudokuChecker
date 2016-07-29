#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <math.h>
#include "sudoku.h"

bool check_for_duplicates(int grid[], int n) {
    /* Checks if arrays contains duplicate integers.
     * Returns true if there are duplicates and false otherwise.
     */
    for(int i=0; i<n; i++) {
        for(int j=i+1; j<n; j++) {
            if(grid[i] == grid[j]) {
                return true;
            }
        }
    }
    return false;

}

bool is_solved(int n, int gridArray[n][n]) {
    /* Determines of sudoku puzzle has been solved
     * Returns true if it has and false otherwise
     */

    //Check rows
    for(int i=0; i<n;i++) {
        int content_of_rows[n];

        for(int j=0; j<n; j++) {
            content_of_rows[j] = gridArray[i][j];
        }
        bool has_duplicates = check_for_duplicates(content_of_rows,n);
        if (has_duplicates) {
            return false;
        }

    }

    //Check columns
    for(int i=0; i<n;i++) {
        int content_of_columns[n];

        for(int j=0; j<n;j++) {
            content_of_columns[i] = gridArray[j][i];
        }

        bool has_duplicates = check_for_duplicates(content_of_columns, n);
        if (has_duplicates) {
            return false;
        }
    }

    //Check subsquares
    int m = sqrt(n);
    for(int i=0; i<n; i += m){
        for(int j=0; j<n; j += m) {
            for(int x=i; x< i+m; x++) {
                for(int y=j; y<j+m;y++){
                    if(x != i && y != j && gridArray[x][y] == gridArray[i][j]){
                        return false;
                    }
                }
            }

        }
    }

    return true;
}


