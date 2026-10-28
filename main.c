#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Solutions.h"

int main(void)
{
    int dice[6];

    srand((unsigned int)time(NULL));

    // Roll six dice
    for (int i = 0; i < 6; i++)
    {
        dice[i] = (rand() % 6) + 1;
    }

    // Print the dice
    printDice(dice);

    return 0;
}