#include <stdlib.h>
#include <string.h>
#include "player.h"

struct player
{
	char name[20];
	char sign;
	int wins;
};

player player_init(char name[], char sign)
{
	player p = malloc(sizeof(struct player));
	if(p != NULL)
	{
		strcpy(p->name, name);
		p->sign = sign;
		p->wins = 0;
	}
	return p;
}

char *get_player_name(player p)
{
	return (p != NULL) ? p->name : NULL;
}

char get_player_sign(player p)
{
	return (p != NULL) ? p->sign : '\0';
}

int get_player_wins(player p)
{
	return (p != NULL) ? p->wins : -1;
}

void inc_player_wins(player p)
{
	if(p != NULL)
		(p->wins)++;
}

void player_free(player p)
{
	free(p);
}