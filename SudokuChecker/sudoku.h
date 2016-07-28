#ifndef __SUDOKU_H__
#define __SUDOKU_H__

#include <ctype.h>
#include <stdbool.h>

bool check_for_duplicates(int * grid);
bool is_solved(int ** gridArray, int n);

#endif
