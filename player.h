#ifndef PLAYER_H
#define PLAYER_H

typedef struct player *player;

player player_init(char name[], char sign);
char *get_player_name(player p);
char get_player_sign(player p);
int get_player_wins(player p);
void inc_player_wins(player p);
void player_free(player p);

#endif