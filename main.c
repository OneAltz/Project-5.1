#include "Solutions.h"

int main(void){
int num = 0, bank_balance = 0, wager = 0;
srand((unsigned int) time(NULL));
bank_balance = set_bank_balance (bank_balance);

    while  (num != 3)
    {
        printf("Do you want to:\n");
        printf("1. Print The Rules For The Game\n");
        printf("2. Play The Game.\n");
        printf("3. Exit The Game.\n\n");
        scanf("%d", &num);
        if(num == 1){print_game_rules ();}
        if(num == 2){while (num != 3){
             int dice[6];

            srand((unsigned int)time(NULL));

            // Roll six dice
            for (int i = 0; i < 6; i++)
            {
              dice[i] = (rand() % 6) + 1;
            }
            printDice(dice);
            }}
    }
return 0;
}