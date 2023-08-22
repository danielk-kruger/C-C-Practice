#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_HOLDER_NAME 50
#define ACCOUNT_ARRAY_LIMIT 100

typedef struct {
    int account_number;
    char account_holder[MAX_HOLDER_NAME];
    float balance;
} BankAccount;

size_t len(BankAccount accounts[]) {
    return sizeof(accounts) / sizeof(accounts[0]);
}

int searchAccount(BankAccount accounts[], int acc_number) {
    for (int i = 0; i < len(accounts); i++)
        if (accounts[i].account_number == acc_number)
            return i;
    
    return -1;
}

bool validateAccount(int account_number, int stored_account) {
    return (account_number == stored_account && account_number > 0);
}

void createAccount(BankAccount accounts[]) {
    int generated_number = rand() % 5999 + 1;
    accounts[len(accounts)].account_number = generated_number;
    printf("\nYour Account Number:  %d\n\n", generated_number);

    printf("\nEnter your account name:  ");
    scanf("%s", accounts[len(accounts)].account_holder);

    printf("\nEnter your initial balance:  ");
    scanf("%f", accounts[len(accounts)].balance);

    printf("\nAccount created Successfully\n");
}

void deposit(BankAccount accounts[]) {
    int acc_number;
    float amount;

    printf("\nInsert your account number: ");
    scanf("%d", &acc_number);

    int index = searchAccount(accounts, acc_number);
    if (index > 0) {
        printf("\nAccount found!\n");
        // BankAccount acc = accounts[index];

        printf("\nInsert deposit amount: ");
        scanf("%f", &amount);
        accounts[index].balance += amount;
        printf("Deposit Successful");
    } else {
        printf("\nInvalid Account Number!\n");
    }
}

void withdraw(BankAccount accounts[]) {
    // withdrawal logic
}

void display(BankAccount accounts[]) {
    // display Balance logic
}

int main() {

}