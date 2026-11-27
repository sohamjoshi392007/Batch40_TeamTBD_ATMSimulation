#include <stdio.h>
#include <string.h>

#define MAX 10


struct Transaction {
    char type[20];
    float amount;
    float balance;
};


struct Account {
    char name[50];
    char card[30];
    char accountNumber[20];
    char bank[30];
    char ifsc[20];
    char status[20];
    char mpin[5];
    float balance;

    struct Transaction history[MAX];
    int count;
};


void checkBalance(struct Account a) {
    printf("\nAvailable Balance: Rs. %.2f\n", a.balance);
}


void saveTransaction(struct Account *a, char type[], float amount) {
    if (a->count < MAX) {
        strcpy(a->history[a->count].type, type);
        a->history[a->count].amount = amount;
        a->history[a->count].balance = a->balance;
        a->count++;
    }
    else {
        printf("\nTransaction history is full!\n");
    }
}

void deposit(struct Account *a) {
    float amount;

    printf("\nEnter deposit amount: Rs. ");
    scanf("%f", &amount);

    if (amount > 0) {
        a->balance += amount;
        saveTransaction(a, "Deposit", amount);

        printf("\nDeposit Successful!");
        printf("\nUpdated Balance: Rs. %.2f\n", a->balance);
    }
    else {
        printf("\nInvalid Amount!\n");
    }
}

void withdraw(struct Account *a) {
    float amount;

    printf("\nEnter withdrawal amount: Rs. ");
    scanf("%f", &amount);

    if (amount <= 0) {
        printf("\nInvalid Amount!\n");
    }
    else if (amount > a->balance) {
        printf("\nInsufficient Balance!\n");
    }
    else {
        a->balance -= amount;
        saveTransaction(a, "Withdrawal", amount);

        printf("\nWithdrawal Successful!");
        printf("\nRemaining Balance: Rs. %.2f\n", a->balance);
    }
}


void changeMPIN(struct Account *a) {
    char oldPin[20], newPin[20], confirmPin[20];

    printf("\nEnter current MPIN: ");
    scanf("%19s", oldPin);

    if (strcmp(oldPin, a->mpin) == 0) {
        printf("Enter new 4-digit MPIN: ");
        scanf("%19s", newPin);

        if (strlen(newPin) == 4) {
            printf("Confirm new MPIN: ");
            scanf("%19s", confirmPin);

            if (strcmp(newPin, confirmPin) == 0) {
                strcpy(a->mpin, newPin);
                printf("\nMPIN Changed Successfully!\n");
            }
            else {
                printf("\nMPIN does not match!\n");
            }
        }
        else {
            printf("\nMPIN must contain exactly 4 characters!\n");
        }
    }
    else {
        printf("\nIncorrect MPIN!\n");
    }
}

void history(struct Account a) {
    printf("\n========== TRANSACTION HISTORY ==========\n");

    if (a.count == 0) {
        printf("No transactions yet.\n");
    }
    else {
        for (int i = 0; i < a.count; i++) {
            printf("\nTransaction %d", i + 1);
            printf("\nType: %s", a.history[i].type);
            printf("\nAmount: Rs. %.2f", a.history[i].amount);
            printf("\nBalance: Rs. %.2f\n", a.history[i].balance);
        }
    }
}


int login(struct Account a) {
    char pin[20];
    int attempts = 3;

    while (attempts > 0) {
        printf("\nEnter your MPIN: ");
        scanf("%19s", pin);

        if (strcmp(pin, a.mpin) == 0) {
            printf("\nLogin Successful!\n");
            return 1;
        }
        else {
            attempts--;
            printf("\nIncorrect MPIN!");
            printf("\nAttempts remaining: %d\n", attempts);
        }
    }

    printf("\nATM BLOCKED!\n");
    return 0;
}


int main() {

    struct Account user = {
        "ATM User",
        "**** **** **** 9012",
        "XXXXXXXX0001",
        "SECURE BANK",
        "ABCD0001234",
        "ACTIVE",
        "1234",
        32500.00,
        {0},
        0
    };

    int choice;

    printf("\n==========================================");
    printf("\n      WELCOME TO SECURE BANK ATM");
    printf("\n==========================================");

    if (!login(user)) {
        return 0;
    }

    do {
        printf("\n====================================");
        printf("\n             ATM MENU");
        printf("\n====================================");

        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Change MPIN");
        printf("\n5. Transaction History");
        printf("\n6. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                checkBalance(user);
                break;

            case 2:
                deposit(&user);
                break;

            case 3:
                withdraw(&user);
                break;

            case 4:
                changeMPIN(&user);
                break;

            case 5:
                history(user);
                break;

            case 6:
                printf("\nThank you for using SECURE BANK ATM!");
                printf("\nHave a great day!\n");
                break;

            default:
                printf("\nInvalid Choice!\n");
        }

    } while(choice != 6);

    return 0;
}
