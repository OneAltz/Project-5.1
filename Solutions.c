#include "Solutions.h"

//This Is the Funtion Prototype For No.1
void print_game_rules(void)
{
    puts("YAHTZEE RULES");
    puts("Two players take turns for 13 rounds.");
    puts("Each player rolls five dice.");
    puts("You may roll up to three times per turn.");
    puts("You may keep any dice between rolls.");
    puts("Each turn, choose one scoring category.");
    puts("A used category cannot be selected again.");
    puts("An invalid combination scores zero.");
    puts("");
    puts("UPPER SECTION:");
    puts("Ones through Sixes score matching dice.");
    puts("Score at least 63 points for a 35-point bonus.");
    puts("");
    puts("LOWER SECTION:");
    puts("Three of a kind: Sum of all dice.");
    puts("Four of a kind: Sum of all dice.");
    puts("Full house: 25 points.");
    puts("Small straight: 30 points.");
    puts("Large straight: 40 points.");
    puts("Yahtzee: 50 points.");
    puts("Chance: Sum of all dice.");
    puts("");
    puts("Additional Yahtzees score 50 points each.");
    puts("The player with the highest total wins.");
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
int are_pair(int dice1[], int dice2[]) 
{
    int count1[6] = {0}, count2[6] = {0}, sum1 = 0, sum2 = 0;
    for(int i = 0; i < 6; i++){ count1[dice1[i]]++; sum1 += dice1[i];}
    for(int i = 0; i < 6; i++){ count2[dice2[i]]++; sum2 += dice2[i];}
    printf("%d", sum1);
    printf("%d", sum2);

    
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