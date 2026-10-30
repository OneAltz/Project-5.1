#include "Solutions.h"

int main(void)
{
    int num = 0;
    int dice1[5] = {0}, dice2[5] = {0};
    int used1[13] = {0}, used2[13] = {0};
    int score1 = 0, score2 = 0, upper1 = 0, upper2 = 0;
    int player = 1, round = 1, choice = 0, points = 0;

    srand((unsigned int)time(NULL));

    while(num != 3)
    {
        printf("\nDo you want to:\n");
        printf("1. Print The Rules For The Game\n");
        printf("2. Play The Game\n");
        printf("3. Exit The Game\n\n");
        printf("Enter Your Choice: ");

        if(scanf("%d", &num) != 1){printf("Invalid Selection\n");continue;}
        if(num == 1){print_game_rules();
        }
        else if(num == 2){
        score1 = 0; score2 = 0;
        upper1 = 0; upper2 = 0;
            for(int i = 0; i < 13; i++){used1[i] = 0;used2[i] = 0;}
            for(round = 1; round <= 13; round++)
            {
                for(player = 1; player <= 2; player++)
                {
                    int *dice;
                    if(player == 1){dice = dice1;}
                    else{dice = dice2;}
                    printf("\nROUND %d OF 13 | PLAYER %d\n", round, player);
                    printf("Press Enter to Roll Your Dice...");
                    roll_dice(dice);
                    for(int roll = 1; roll <= 3; roll++)
                    {
                        printf("PLAYER %d | ROUND %d | ROLL %d OF 3\n\n", player, round, roll);
                        printDice(dice);
                        if(roll == 3){break;}
                        printf("Score these dice now? (Y/N): ");
                        if(yes_no() == 'y'){break;}
                        for(int i = 0; i < 5; i++)
                        {
                            printf("Reroll Die %d? (Y/N): ", i + 1);
                            if(yes_no() == 'y'){dice[i] = roll_die();}
                        }
                    }

                    printf("\nPLAYER %d FINAL DICE\n\n", player);
                    printDice(dice);
                    points = are_pair(dice1, dice2, used1, used2, player, &choice);
                    if(points < 0){printf("Unable to record score.\n");return 1;}
                    if(player == 1)
                    {
                        score1 += points;
                        if(choice >= 1 && choice <= 6){upper1 += points;} printf("Player 1 Total: %d\n", score1);
                    }
                    else
                    {
                        score2 += points;

                        if(choice >= 1 && choice <= 6)
                        {
                            upper2 += points;
                        }

                        printf("Player 2 Total: %d\n", score2);
                    }
                }
            }
            // Final scores
            printf("\n========== GAME OVER ==========\n");

            printf("Player 1 Score: %d\n", score1);
            printf("Player 2 Score: %d\n", score2);

            if(score1 > score2)
            {
                printf("PLAYER 1 WINS!\n");
            }
            else if(score2 > score1)
            {
                printf("PLAYER 2 WINS!\n");
            }
            else
            {
                printf("THE GAME IS A TIE!\n");
            }
        }
        else if(num == 3)
        {
            printf("Thanks For Playing Yahtzee!\n");
        }
        else
        {
            printf("Invalid Selection\n");
        }
    }

    return 0;
}