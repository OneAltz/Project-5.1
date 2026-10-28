#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>
//This Is the Funtion Prototype For No.1
void print_game_rules (void);
//This Is the Funtion Prototype For No.2
void printDice(const int dice[6]);
void beautiful_role(void);
//This Is the Funtion Prototype For No.3
double get_bank_balance (int bank_balance);
//This Is the Funtion Prototype For No.2
double set_bank_balance (int bank_balance);
//This Is the Funtion Prototype For No.3
double get_wager_amount (void);
//This Is the Funtion Prototype For No.4
int check_wager_amount (double wager, double bank_balance); 
//This Is the Funtion Prototype For No.5
int roll_die (void);
//This Is the Funtion Prototype For No.6
int calculate_sum_dice(int die1_value, int die2_value); 
//This Is the Funtion Prototype For No.7
int is_win_loss_or_point (int sum_dice);
//This Is the Funtion Prototype For No.8
int is_point_loss_or_neither (int sum_dice, int point_value);
//Is the Funtion Prototype For No.9
double adjust_bank_balance (double bank_balance, double wager_amount, int win);
//Is the Funtion Prototype For No.10
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
//Is the Funtion Prototype For No.11
double double_or_nothing (double bank_balance, double wager_amount, int add_or_subtract);
//Is the Funtion Prototype For No.12
void save_game_results (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
//Is the Funtion Prototype For No.13
void Chatter_Messages_Win_Loss (int win);
//Is the Funtion Prototype For No.14
void Chatter_messages_Low_Bank (double current_bank_balance);
//Is the Funtion Prototype For No.15
void Chatter_messages_High_Bank(double bank_balance);
//Is the Funtion Prototype For No.16
void Chatter_messages_Neutral(double bank_balance);
#endif