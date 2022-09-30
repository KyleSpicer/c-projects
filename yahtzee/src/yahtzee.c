#include "yahtzee.h"

int
main()
{
    srand(time(NULL)); // seed time for rand func

    greeting_menu(); // display greeting to program

    // allocate memory for all player pointers
    player_t **pp_player_container = calloc(MAX_PLAYERS, sizeof(player_t *));

    if (!pp_player_container)
    {
        perror("Unable to allocate array memory.\n");
        return 1;
    }

    // get amount of players
    long num_players = how_many_players();

    // allocate memory for player structs
    for (int idx = 0; idx < num_players; idx++)
    {
        pp_player_container[idx] = make_player(idx);
        printf("Player %d is %s\n", idx + 1, pp_player_container[idx]->name);
    }

    // main game play funcs
    gameplay(pp_player_container, num_players);

    // clean allocated memory
    clean_your_memory(pp_player_container, num_players);
}

/* end of file */