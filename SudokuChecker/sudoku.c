#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>
#include "sudoku.h"

bool check_for_duplicates(int * grid){
    /* Checks if arrays contains duplicate integers.
     * Returns true if there are duplicates and false otherwise.
     */
    for(int i=0; i<sizeof(grid)/sizeof(int);i++) {
        int holder = grid[i];
        for(int j=0; j<sizeof(grid)/sizeof(int);j++) {
            if(holder == grid[j]){
                return true;
            }
        }
    }
    return false;

}

bool is_solved(int ** gridArray, int n) {
    /* Determines of sudoku puzzle has been solved
     * Returns true if it has and false otherwise
     */

    //Check rows
    for(int i=0; i<n;i++) {
        bool has_duplicates = check_for_duplicates(gridArray[i]);
        if (has_duplicates) {
            return false;
        }
    }

    //Check columns
    int * content_of_columns = (int *)malloc(n * sizeof(int));
    for(int i=0; i<n;i++) {
        for(int j=0; j<n;j++) {
            content_of_columns[j] = gridArray[i][j];
            bool has_duplicates = check_for_duplicates(content_of_columns);
            if (has_duplicates) {
                return false;
            }
        }
    }

    //Check subsquares
    int m = sqrt(n);
    int * content_of_subsquare = (int *)malloc(n * sizeof(int));
    for(int i=0; i< n; i+=m) {
        for(int j=0; j<n; j+=m) {
            for(int x=i; x<m; x++) {
                for(int y=j; y<m; y++) {
                    content_of_subsquare[x] = gridArray[x][y];
                    if(check_for_duplicates(content_of_subsquare)) {

                    }
                }
            }
        }
    }
    free(content_of_subsquare);

    return false;
}


