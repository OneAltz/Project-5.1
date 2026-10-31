#include "Solutions.h"

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

static const char *faces[7][3] = {
    {"       ", "       ", "       "},
    {"       ", "   o   ", "       "},
    {" o     ", "       ", "     o "},
    {" o     ", "   o   ", "     o "},
    {" o   o ", "       ", " o   o "},
    {" o   o ", "   o   ", " o   o "},
    {" o o o ", "       ", " o o o "}
};

void printDice(const int dice[5])
{
    for(int i = 0; i < 5; i++){printf("  Die %-4d ", i + 1);}
    printf("\n");
    for(int i = 0; i < 5; i++){printf("+-------+  ");}
    printf("\n");
    for(int row = 0; row < 3; row++){for(int i = 0; i < 5; i++){if(dice[i] >= 1 && dice[i] <= 6){printf("|%s|  ", faces[dice[i]][row]);}else{printf("|???????|  ");}}printf("\n");}
    for(int i = 0; i < 5; i++){printf("+-------+  ");}
    printf("\n\n");
}

int roll_die(void)
{
    return (rand() % 6) + 1;
}

void roll_dice(int dice[5])
{
    for(int i = 0; i < 5; i++){dice[i] = roll_die();}
}

void calculate_points(int count[7], int sum, int points[13])
{
    int three = 0, four = 0, five = 0, pair = 0, exact_three = 0;

    for(int i = 1; i <= 6; i++){if(count[i] >= 3){three = 1;}
    if(count[i] >= 4){four = 1;}
    if(count[i] == 5){five = 1;}
    if(count[i] == 2){pair = 1;}
    if(count[i] == 3){exact_three = 1;}}
    for(int i = 0; i < 6; i++){points[i] = count[i + 1] * (i + 1);}
    points[6] = 0;
    if(three == 1){points[6] = sum;}
    points[7] = 0;
    if(four == 1){points[7] = sum;}
    points[8] = 0;
    if(exact_three == 1 && pair == 1){points[8] = 25;}
    points[9] = 0;
    if(count[1] && count[2] && count[3] && count[4]){points[9] = 30;}
    if(count[2] && count[3] && count[4] && count[5]){points[9] = 30;}
    if(count[3] && count[4] && count[5] && count[6]){points[9] = 30;}
    points[10] = 0;
    if(count[1] && count[2] && count[3] && count[4] && count[5]){points[10] = 40;}
    if(count[2] && count[3] && count[4] && count[5] && count[6]){points[10] = 40;}
    points[11] = 0;
    if(five == 1){points[11] = 50;}
    points[12] = sum;
}

int are_pair(int dice1[], int dice2[], int used1[13], int used2[13], int player, int *selected_category)
{
    int count[7] = {0}, sum = 0, points[13] = {0}, choice = 0;
    bool TA = true;
    int *dice, *used;
    char *names[13] = {"Ones", "Twos", "Threes", "Fours", "Fives", "Sixes","Three of a Kind", "Four of a Kind", "Full House","Small Straight", "Large Straight", "Yahtzee", "Chance"};
    if(player == 1){dice = dice1; used = used1;}
    else if(player == 2){dice = dice2; used = used2;}
    else{printf("Invalid Player\n"); return -1;}
    for(int i = 0; i < 5; i++){if(dice[i] < 1 || dice[i] > 6){printf("Invalid Die Value\n"); return -1;}count[dice[i]]++; sum += dice[i];}
    calculate_points(count, sum, points);
    printf("\nPlayer %d Sum: %d\n", player, sum);
    for(int i = 1; i <= 6; i++){if(count[i] == 2){printf("You Have a Pair of %d\n", i);}}
    for(int i = 1; i <= 6; i++){if(count[i] >= 3){printf("You Have a Three-of-a-kind %d\n", i);}}
    for(int i = 1; i <= 6; i++){if(count[i] >= 4){printf("You Have a Four-of-a-kind %d\n", i);}}
    for(int i = 1; i <= 6; i++){if(count[i] == 5){printf("You Have a Yahtzee!\n");}}
    for(int i = 1; i <= 6; i++){if(count[i] > 0 && used[i - 1] == 0){printf("You Have a Sum of %d's\n", i);}}
    if(points[8] == 25){printf("You Have a Full House\n");}
    if(points[9] == 30){printf("You Have a Small Straight\n");}
    if(points[10] == 40){printf("You Have a Large Straight\n");}
    if(used[12] == 0){printf("You Have Chance Available\n");}
    printf("\nPLAYER %d SCORING OPTIONS\n", player);
    for(int i = 0; i < 13; i++)
    {
        if(used[i] == 0){printf("%2d. %-18s %d Points\n", i + 1, names[i], points[i]);}
        else if(i == 11 && points[11] == 50){printf("12. Additional Yahtzee - 50 Points\n");}
        else{printf("%2d. %-18s USED\n", i + 1, names[i]);}
    }
while(1)
{
    printf("\nSelect Your Scoring Category (1-13): ");
    int result = scanf("%d", &choice);

    if(result == EOF){return -1;}
    if(result != 1){clear_input(); printf("Invalid Input\n"); continue;}

    clear_input();

    if(choice < 1 || choice > 13){printf("Invalid Selection\n"); continue;}
    if(used[choice - 1] == 1 && !(choice == 12 && points[11] == 50)){printf("You Have Already Used This Category\n"); continue;}

    used[choice - 1] = 1;
    *selected_category = choice;

    printf("\nPlayer %d Scored %d Points In %s!\n", player, points[choice - 1], names[choice - 1]);

    return points[choice - 1];
}
}
char yes_no(void)
{
    char answer;

    while(1)
    {
        if(scanf(" %c", &answer) != 1){exit(0);}

        if(answer == 'Y' || answer == 'y'){return 'y';}
        if(answer == 'N' || answer == 'n'){return 'n';}

        printf("Please Enter Y or N: ");
    }
}