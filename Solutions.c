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
    for (int i = 0; i < 6; i++){printf("+-------+  ");}
    printf("\n");
    for (int row = 0; row < 3; row++){for (int i = 0; i < 6; i++){int value = dice[i];if (value >= 1 && value <= 6){printf("|%s|  ", faces[value][row]);}}printf("\n");}
    for (int i = 0; i < 6; i++){printf("+-------+  ");}
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
int are_pair(int dice1[], int dice2[], int used1[13], int used2[13], int player)
{
    int count[7] = {0}, sum = 0, Pro = 0, comm2 = 0, comm4 = 0;
    int three = 0, four = 0, five = 0, pair = 0, exact_three = 0, small = 0, large = 0, choice = 0;
    int *dice, *used;
    if(player == 1) {dice = dice1; used = used1;}
    else if(player == 2) {dice = dice2; used = used2;}
    else {printf("Invalid Player\n"); return -1;}
    for(int i = 0; i < 5; i++){if(dice[i] < 1 || dice[i] > 6) {printf("Invalid Die Value\n"); return -1;}count[dice[i]]++;sum += dice[i];}
    printf("\nPlayer %d Sum: %d\n", player, sum);
    for(int i = 1; i <= 6; i++){if(count[i] >= 3) {three = 1;}if(count[i] >= 4) {four = 1;}if(count[i] == 5) {five = 1;}if(count[i] == 2) {pair = 1;}if(count[i] == 3) {exact_three = 1;}}
    for(int i = 1; i <= 6; i++) {if(count[i] == 2){printf("You Have a Pair of %d\n", i);}}
    for(int i = 1; i <= 6; i++) {if(count[i] >= 3 && used[6] != 1){printf("You Have a Three-of-a-kind %d\n", i); Pro++; printf("Would You like to Proceed, Type No. 7\n");}}
    for(int i = 1; i <= 6; i++) {if(count[i] >= 4 && used[7] != 1){printf("You Have a Four-of-a-kind %d\n", i); Pro++; printf("Would You like to Proceed, Type No. 8\n");}}
    for(int i = 1; i <= 6; i++) {if(count[i] == 5){printf("You Have a Yahtzee!\n"); Pro++; printf("Would You like to Proceed, Type No. 12\n");}}
    if(count[1] > 0 && used[0] != 1){printf("You Have a Sum of Ones\n"); Pro++; printf("Would You like to Proceed, Type No. 1\n");}
    if(count[2] > 0 && used[1] != 1){printf("You Have a Sum of Twos\n"); Pro++; printf("Would You like to Proceed, Type No. 2\n");}
    if(count[3] > 0 && used[2] != 1){printf("You Have a Sum of Threes\n"); Pro++; printf("Would You like to Proceed, Type No. 3\n");}
    if(count[4] > 0 && used[3] != 1){printf("You Have a Sum of Fours\n"); Pro++; printf("Would You like to Proceed, Type No. 4\n");}
    if(count[5] > 0 && used[4] != 1){printf("You Have a Sum of Fives\n"); Pro++; printf("Would You like to Proceed, Type No. 5\n");}
    if(count[6] > 0 && used[5] != 1){printf("You Have a Sum of Sixes\n"); Pro++; printf("Would You like to Proceed, Type No. 6\n");}
    for(int i = 1; i <= 6; i++){if(count[i] > 0){comm2++;if(comm2 == 5) {large = 1; if(used[10] != 1){printf("You Have a Large Straight\n"); Pro++; printf("Would You like to Proceed, Type No. 11\n");}}}if(count[i] == 0) {comm2 = 0;}}
    for(int i = 1; i <= 6; i++){if(count[i] > 0){comm4++;if(comm4 == 4) {small = 1; if(used[9] != 1){printf("You Have a Small Straight\n"); Pro++; printf("Would You like to Proceed, Type No. 10\n");}}}if(count[i] == 0) {comm4 = 0;}}
    if(exact_three == 1 && pair == 1 && used[8] != 1){printf("You Have a Full House\n");Pro++;printf("Would You like to Proceed, Type No. 9\n");}
    if(used[12] != 1){printf("You Have Chance Available\n");Pro++;printf("Would You like to Proceed, Type No. 13\n");}
    if(Pro == 0) {printf("You Have No Unused Matching Combinations\n");}
} 
//This Is the Funtion Prototype For No.7
int is_win_loss (int are_pair)
{

}
//This Is the Funtion Prototype For No.8
void clear_input(void)
{
    int c;
    while((c = getchar()) != '\n' && c != EOF) {}
}

//Is the Funtion Prototype For No.9
char yes_no(void)
{
    char answer;

    while(1)
    {
        if(scanf(" %c", &answer) != 1) {exit(0);}
        clear_input();
        if(answer == 'Y' || answer == 'N') {return answer;}
        if(answer == 'y' || answer == 'n') {return answer;}
        printf("Please enter Y or N: ");
    }
}
//Is the Funtion Prototype For No.13
//Is the Funtion Prototype For No.14
//Is the Funtion Prototype For No.15
//Is the Funtion Prototype For No.16