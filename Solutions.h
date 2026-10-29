#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

//This Is the Funtion Prototype For No.1
void print_game_rules(void);
//This Is the Funtion Prototype For No.3
//This Is the Funtion Prototype For No.4
void printDice(const int dice[6]);
//This Is the Funtion Prototype For No.5
int roll_die(void);
//This Is the Funtion Prototype For No.6
void roll_dice(int dice[6]);
//This Is the Funtion Prototype For No.6
int are_pair(int dice1[], int dice2[], int used1[13], int used2[13], int player);
//This Is the Funtion Prototype For No.7
int is_win_loss (int are_pair);
//This Is the Funtion Prototype For No.8
void clear_input(void);
//Is the Funtion Prototype For No.9
char yes_no(void);
#endif