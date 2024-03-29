#ifndef _FILECONTROL_H
#define _FILECONTROL_H

#include <stdint.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct Account {
    int32_t accountNo;
    double openBal;
    double currentBal;
    double closeBal;
    int8_t type;
};

struct Client{
    char firstN[20];
    char lastN[20];
    char username[20];
    int32_t pin;
    int32_t clientNo;
    int32_t loanAcctNo;
    int32_t savAcctNo;
    int32_t chequeAcctNo;
};

struct Transaction{
    int32_t fromAcct;
    int32_t *toAcct;
    double amount;
    int8_t type;
};

int8_t get_file_dimensions(const char *file_location, int16_t *lines, int16_t *width);
/*
open_accounts() opens the Accounts.txt file, located in the same directory
parsing over the file, tokenizing and then creating an array of Account structs
to pass back to the prior function
inputs: struct Account **all_accounts
memory address to desired array of structs
return: int8_t
number of accounts in the array
*/
void open_CD(struct Client *clients, int8_t num_clients, int8_t MAX_WIDTH);
void open_Au(struct Client *clients, int8_t num_clients, int8_t MAX_WIDTH);
void open_Acc(struct Account *accounts, int8_t num_accounts, int8_t MAX_WIDTH);

void Client_Init(struct Client *client);

int8_t username_exists(struct Client *clients,int8_t num_clients,char *username);
bool pin_correct(struct Client client,int32_t pin);

#endif
