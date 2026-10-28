#ifndef SOLUTIONS_H
#define SOLUTIONS_H
#define _CRT_SECURE_NO_WARNINGS 
#include <stdio.h> 
#include <stdlib.h>
#include <math.h>
#include <time.h>

void print_game_rules (void);
void printDice(const int dice[6]);
void beautiful_role(void);
int roll_die(void);
void roll_dice(int dice[6]);
double get_bank_balance (int bank_balance);
double set_bank_balance (int bank_balance);
double get_wager_amount (void);
int check_wager_amount (double wager, double bank_balance); 
int roll_die (void);
int calculate_sum_dice(int die1_value, int die2_value); 
int is_win_loss_or_point (int sum_dice);
int is_point_loss_or_neither (int sum_dice, int point_value);
double adjust_bank_balance (double bank_balance, double wager_amount, int win);
void chatter_messages (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
double double_or_nothing (double bank_balance, double wager_amount, int add_or_subtract);
void save_game_results (int number_rolls, int win_loss_neither, double initial_bank_balance, double current_bank_balance);
void Chatter_Messages_Win_Loss (int win);
void Chatter_messages_Low_Bank (double current_bank_balance);
void Chatter_messages_High_Bank(double bank_balance);
void Chatter_messages_Neutral(double bank_balance);
#endif