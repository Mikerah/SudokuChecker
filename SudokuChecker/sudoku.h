#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <ctype.h>
#include <stdbool.h>

bool check_for_duplicates(int grid[], int n);
bool has_zeros(int grid[], int n);
bool is_solved(int n, int gridArray[n][n]);

#endif
