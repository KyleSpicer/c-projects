#ifndef YAHTZEE_H
#define YAHTZEE_H

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <ctype.h>
#include <string.h>
#include <time.h>
#include <wchar.h>
#include <unistd.h>

#define MAX_NAME_LEN 15
#define MAX_PLAYERS  4
#define MAX_NUM_DICE 5
#define MAX_DICE_BYTES 20

struct scorecard_t
{
    int aces;
    int twos;
    int threes;
    int fours;
    int fives;
    int sixes;
    int three_of_kind;
    int four_of_kind;
    int full_house;
    int small_straight;
    int large_straight;
    int yahtzee;
    int total;
};

typedef struct player_t
{
    char         name[MAX_NAME_LEN];
    unsigned int die_1 : 3;
    unsigned int die_2 : 3;
    unsigned int die_3 : 3;
    unsigned int die_4 : 3;
    unsigned int die_5 : 3;

    struct scorecard_t player_scorecard;

} player_t;

/* clears console for aesthetic */
void clear_screen();

/* display introduction to game*/
void greeting_menu();

/* receives user input for amount of players, between 1 - 4*/
long how_many_players();

/* creates player struct from user input*/
player_t *make_player(int count);

/* randomly generates 5 numbers to mimic dice roll*/
int die_roll();

/* prints dice values as unicode image to console*/
void die_print(int die_val);

/* main logic for gameplay*/
void gameplay(player_t **pp_player_container, int num_players);

/* free all allocated memory */
void clean_your_memory(struct player_t **pp_player_container, long num_players);

#endif /* YAHTZEE_H*/

/* end of file */