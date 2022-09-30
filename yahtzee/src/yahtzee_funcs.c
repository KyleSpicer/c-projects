#include "yahtzee.h"

/* clears console for aesthetic */
void
clear_screen()
{
    system("clear");
}

/* display introduction to game*/
void
greeting_menu()
{
    clear_screen();
    printf("Welcome to Yahtzee!\n");
}

/* receives user input for amount of players, between 1 - 4*/
long
how_many_players()
{
    char  user_input[MAX_PLAYERS];
    long  num_players = 0;
    char *remaining_string;

    while (num_players < 1 || num_players > 4)
    {
        printf("\nEnter number of players (1 - 4): ");
        fgets(user_input, 4, stdin);

        num_players = strtol(user_input, &remaining_string, 10);

        if (!remaining_string)
        {
            break;
        }
    }

    return num_players;
}

/* creates player struct from user input*/
player_t *
make_player(int count)
{
    char temp_name[MAX_NAME_LEN]; // temp var to hold name

    printf("\nPlayer %d, enter your name: ", count + 1);
    fgets(temp_name, MAX_NAME_LEN, stdin);

    // removes newline from fgets
    temp_name[strcspn(temp_name, "\n")] = 0;

    // create struct for player
    player_t *player = calloc(1, sizeof(player_t));

    if (!player)
    {
        perror("Unable to allocate array memory for struct.\n");
        return 0;
    }

    // copy temp name into struct name
    strncpy(player->name, temp_name, sizeof(temp_name));

    return player;
}

/* randomly generates 5 numbers to mimic dice roll*/
int
die_roll()
{
    int die_value = 0;
    // srand(time(NULL));

    die_value = (rand() % 6) + 1;

    return die_value;
}

/* prints dice values as unicode image to console*/
void
die_print(int die_val)
{
    const char *one   = "\u2680";
    const char *two   = "\u2681";
    const char *three = "\u2682";
    const char *four  = "\u2683";
    const char *five  = "\u2684";
    const char *six   = "\u2685";

    switch (die_val)
    {
        case 1:
            printf(" %s  ", one);
            break;
        case 2:
            printf(" %s  ", two);
            break;
        case 3:
            printf(" %s  ", three);
            break;
        case 4:
            printf(" %s  ", four);
            break;
        case 5:
            printf(" %s  ", five);
            break;
        case 6:
            printf(" %s  ", six);
            break;
    }
}

/* main logic for gameplay*/
void
gameplay(player_t **pp_player_container, int num_players)
{
    clear_screen();
    printf("Let's begin!\n\n");
    printf("Shaking dice....\n");
    sleep(1);
    bool still_playing = true;
    while (still_playing)
    {
        for (int player = 0; player < num_players; player++)
        {
            int dice_array[MAX_DICE_BYTES];
            system("clear");
            printf("%s's turn: \n\n", pp_player_container[player]->name);

            printf(" 1   2   3   4   5\n");
            for (int die = 0; die < 5; die++)
            {
                dice_array[die] = die_roll();
                die_print(dice_array[die]);

                switch (die)
                {
                    case 0:
                        pp_player_container[player]->die_1 = die;
                        break;

                    case 1:
                        pp_player_container[player]->die_2 = die;
                        break;

                    case 2:
                        pp_player_container[player]->die_3 = die;
                        break;

                    case 3:
                        pp_player_container[player]->die_4 = die;
                        break;

                    case 4:
                        pp_player_container[player]->die_5 = die;
                        break;
                }
            }

            char decision[10];
            printf("\n\nWould you like to reroll any dice? (y/n): ");
            fgets(decision, 10, stdin);

            if (strncmp(decision, "y\n", sizeof(decision)) == 0)
            {
                printf("keep it going\n");
            }
            else
            {
                printf(
                    "\n\nstart logic for populating struct and scorecard.\n");
            }

            printf("\n\n");
        }

        break;
    }
}

/* free all allocated memory */
void
clean_your_memory(struct player_t **pp_player_container, long num_players)
{
    // loops through and frees all allocated memory in container
    for (int idx = 0; idx < num_players; idx++)
    {
        free(&(pp_player_container[idx])->name);
    }

    free(pp_player_container);
}

/* end of file */