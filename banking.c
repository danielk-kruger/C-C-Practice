#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HOLDER_NAME 50
#define ACCOUNT_ARRAY_LIMIT 100
#define MAX_LOGIN_ATTEMPS 3

typedef struct {
    int account_number;
    char account_holder[MAX_HOLDER_NAME];
    float balance;
} BankAccount;

size_t len(BankAccount accounts[]) {
    return sizeof(accounts) / sizeof(BankAccount);
}

int searchAccount(BankAccount accounts[], int acc_number, int counter) {
    for (int i = 0; i < counter; i++)
        if (accounts[i].account_number == acc_number)
            return i;
    
    return -1;
}

int validateAccount(BankAccount accounts[], int counter) {
    int acc_number;

    printf("Please login with your bank number to continue: \n");
    printf("=>  ");
    scanf("%d", &acc_number);
    getchar();

    return searchAccount(accounts, acc_number, counter);
}

void createAccount(BankAccount accounts[], int *counter) {
    int generated_number = rand() % 5999 + 1000;

    // printf("\nlength of accounts array: %d", *counter);
    accounts[*counter].account_number = generated_number;
    printf("\nYour Account Number:  %d\n", accounts[*counter].account_number);

    printf("\nEnter your account name:  ");
    scanf("%s", &accounts[*counter].account_holder);

    printf("\nEnter your initial balance:  ");
    scanf("%f", &accounts[*counter].balance);

    printf("\nAccount created Successfully\n");
    (*counter)++;
}

void deposit(BankAccount account) {
    // int acc_number;
    float amount;

    printf("\nInsert deposit amount: ");
    scanf("%f", &amount);

    account.balance += amount;
    printf("Deposit Successful");
}

void withdraw(BankAccount account) {
    float amount;

    printf("\nEnter the amount to withdraw: ");
    scanf("%f", &amount);

    if (account.balance >= amount)
        account.balance -= amount;
    else
        printf("\nInsufficient funds!\n");
    
    printf("\nWithdrawal Successful!\n");
}

void display(BankAccount account) {
    printf("\n\nAccount Holder: %s", account.account_holder);
    printf("\n\nBalance: %.2f", account.balance);
}

void start_system(BankAccount account) {
    int choice;

    do {
        printf("\nBanking System Menu:\n");
        printf("1. Deposit\n");
        printf("2. Withdraw\n");
        printf("3. Display Balance\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");

        scanf("%d", &choice);

        switch (choice) {
            case 1:
                deposit(account);
                break;
            case 2:
                withdraw(account);
                break;
            case 3:
                display(account);
                break;
            case 4:
                printf("\n\nLogging out...\n");
                break;
        }
    } while (choice != 4);
}

int main() {
    BankAccount accounts[ACCOUNT_ARRAY_LIMIT];
    int counter = len(accounts);
    int acc_number;
    int current_attempts = 0;
    // bool isLoggedIn = false;
    // int opt;
    int initial_option;
    printf("Bank System!\n\n");
    

    do {
        printf("1. Log-in\n");
        printf("2. Create Account\n");
        printf("3. Exit\n");
        printf("=>  ");
        scanf("%d", &initial_option); 

        switch (initial_option) {
            case 1:
                while (current_attempts < MAX_LOGIN_ATTEMPS) {
                    int index = validateAccount(accounts, counter);

                    if (index >= 0) {
                        printf("\nLogin Successful!\n");
                        printf("Welcome %s\n", accounts[index].account_holder);
                        start_system(accounts[index]);
                        break;
                    } else{
                        printf("\nInvalid Try again...\n");
                        current_attempts++;
                    }
                }
                break;
            case 2:
                createAccount(accounts, &counter);
                break;
            case 3:
                printf("\nQuitting System...\n");
                break;
        }
    } while (initial_option != 3);

    return 0;
}