#include <stdio.h>
#include <stdlib.h>
#include "grid.h"
#include "player.h"

static const int grid_size = 3;

struct grid
{
	player board[3][3];
};

grid grid_init()
{
	grid g = malloc(sizeof(struct grid));
	if(g != NULL)
		grid_clear(g);
	return g;
}

void grid_clear(grid g)
{
	if(g != NULL)
	{
		for(int i = 0; i < grid_size; i++)
			for(int j = 0; j < grid_size; j++)
				g->board[i][j] = NULL;
	}
}

void grid_print(grid g)
{
	if(g != NULL)
	{
		for(int i = 0; i < grid_size; i++)
		{
			for(int j = 0; j < grid_size; j++)
			{
				printf(" %c ", g->board[i][j] != NULL ? get_player_sign(g->board[i][j]) : ' ');
				if(j != grid_size - 1)
					printf("|");
			}
		
			puts("");
			if(i != grid_size - 1)
				printf("------------\n");
		}
	}
}

int is_valid_move(grid g, int row, int column)
{
	if((row >=0 && row <= 2) && (column >= 0 && column <= 2))
		if(g != NULL && g->board[row][column] == NULL)
			return 1;
	return 0;
}

void grid_update(grid g, player p, int row, int column)
{
	if(g != NULL && p != NULL)
		g->board[row][column] = p;
}

player check_winner(grid g)
{
	const int check[8][3] = 
	{
		{0, 1, 2}, {3, 4, 5}, {6, 7, 8},	// rows
		{0, 3, 6}, {1, 4, 7}, {2, 5, 8},	// columns
		{0, 4, 8}, {2, 4, 6}				// diagonals
	};

	for(int i = 0; i < 8; i++)
	{
		if(*(*(g->board) + check[i][0]) == *(*(g->board) + check[i][1]) &&
			*(*(g->board) + check[i][0]) == *(*(g->board) + check[i][2]))
			return *(*(g->board) + check[i][0]);
	}
	return NULL;
}

void grid_free(grid g)
{
	free(g);
}