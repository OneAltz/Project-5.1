#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

//This Is the Funtion Prototype For No.1
void print_game_rules(void);
//This Is the Funtion Prototype For No.2
void printDice(const int dice[5]);
//This Is the Funtion Prototype For No.3
int roll_die(void);
//This Is the Funtion Prototype For No.4
void roll_dice(int dice[5]);
//This Is the Funtion Prototype For No.5
void calculate_points(int count[7], int sum, int points[13]);
//This Is the Funtion Prototype For No.6
int are_pair(int dice1[], int dice2[], int used1[13], int used2[13], int player, int *selected_category);
//This Is the Funtion Prototype For No.8
char yes_no(void);

#endif