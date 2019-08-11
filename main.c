#include <stdio.h>
#include "player.h"
#include "grid.h"

#define PLAYERS	2

void clear_chat(int n);
void play_game(player parray[]);
void print_scoreboard(player parray[]);

int main()
{
	player parray[PLAYERS];

	char name[20], sign;
	for(int i = 0; i < PLAYERS; i++)
	{
		printf("Inserisci il nome del %d° giocatore: ", i + 1);
		scanf("%s", name);
		printf("Inserisci il segno del %d° giocatore: ", i + 1);
		scanf(" %c", &sign);
		parray[i] = player_init(name, sign);
	}

	play_game(parray);

	for(int i = 0; i < PLAYERS; i++)
		player_free(parray[i]);

	return 0;
}

void clear_chat(int n)
{
	for(int i = 1; i <= n; i++)
		printf("\n");
}

void play_game(player parray[])
{
	int turn = 0, player_turn = 0;
	player winner = NULL;

	grid g = grid_init();

	do
	{
		clear_chat(5);
		printf("E' il turno di %s\n", get_player_name(parray[player_turn]));
		grid_print(g);

		int row, column;
		do
		{
			printf("Inserisci la prossima mossa (riga colonna): ");
			scanf("%d%d", &row, &column);
			row--;
			column--;
		}
		while(!is_valid_move(g, row, column));

		grid_update(g, parray[player_turn], row, column);
		player_turn = (player_turn + 1) % PLAYERS;
		turn++;

		winner = check_winner(g);
	}
	while(turn < 9 && winner == NULL);

	clear_chat(5);
	if(winner != NULL)
	{
		printf("Il vincitore è: %s\n", get_player_name(winner));
		inc_player_wins(winner);
	}
	else puts("Pareggio");

	grid_print(g);
	grid_free(g);
	puts("");
	print_scoreboard(parray);

	char response;
	printf("\nVuoi giocare ancora? (y/n) ");
	scanf(" %c", &response);

	if(response == 'y')
		play_game(parray);
}

void print_scoreboard(player parray[])
{
	puts("| SCOREBOARD |");
	printf("%-20s\t%s\n", "Nome", "Vittorie");
	for(int i = 0; i < PLAYERS; i++)
		printf("%-20s\t%2d\n", get_player_name(parray[i]), get_player_wins(parray[i]));
}