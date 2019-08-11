#ifndef GRID_H
#define GRID_H

#include "player.h"

typedef struct grid *grid;

grid grid_init();
void grid_clear(grid g);
void grid_print(grid g);
int is_valid_move(grid g, int row, int column);
void grid_update(grid g, player p, int row, int column);
player check_winner(grid g);
void grid_free(grid g);

#endif