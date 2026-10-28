#include "Solutions.h"

//This Is the Funtion Prototype For No.1
void print_game_rules (void)
{
    printf("Welcome to the game! Here are the rules:\n");
    printf("1. You start with a bank balance.\n");
    printf("2. You place a wager, from your bank balance starting at 100$.\n");
    printf("3. You roll two dice.\n");
    printf("4. The sum of the dice determines if you win, lose, or set a point.\n");
}
//This Is the Funtion Prototype For No.3
//This will Print the Insides of the die 
static const char *faces[7][3] = {
    {"       ", "       ", "       "}, // 0
    {"       ", "   o   ", "       "}, // 1
    {" o     ", "       ", "     o "}, // 2
    {" o     ", "   o   ", "     o "}, // 3
    {" o   o ", "       ", " o   o "}, // 4
    {" o   o ", "   o   ", " o   o "}, // 5
    {" o o o ", "       ", " o o o "}  // 6
};
//This Is the Funtion Prototype For No.4
// Display all six dice in one row
void printDice(const int dice[6])
{
    // Top border
    for (int i = 0; i < 6; i++)
    {
        printf("+-------+  ");
    }
    printf("\n");

    // Print the three rows of dots
    for (int row = 0; row < 3; row++)
    {
        for (int i = 0; i < 6; i++)
        {
            int value = dice[i];

            if (value >= 1 && value <= 6)
            {
                printf("|%s|  ", faces[value][row]);
            }
        }
        printf("\n");
    }

    // Bottom border
    for (int i = 0; i < 6; i++)
    {
        printf("+-------+  ");
    }
    printf("\n\n");
}
//This Is the Funtion Prototype For No.5
int roll_die(void)
{
    return (rand() % 6) + 1;
}
//This Is the Funtion Prototype For No.6
void roll_dice(int dice[6])
{
    for (int i = 0; i < 6; i++)
    {
        dice[i] = roll_die();
    }
}
//This Is the Funtion Prototype For No.6
int are_pair(int die1_value[], int die2_value[]) 
{

}
//This Is the Funtion Prototype For No.7
int is_win_loss (int are_pair)
{

}
//This Is the Funtion Prototype For No.8
//Is the Funtion Prototype For No.9
//Is the Funtion Prototype For No.13
//Is the Funtion Prototype For No.14
//Is the Funtion Prototype For No.15
//Is the Funtion Prototype For No.16