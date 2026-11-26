#include <stdio.h>

/* Function declarations */
void displayMenu(void);
void checkBalance(double balance);
double depositMoney(double balance);
double withdrawMoney(double balance);

int main(void) {
    int choice;
    double balance = 10000.00; /* Demo account starting balance in Rs. */
    int running = 1;

    printf("========================================\n");
    printf("       WELCOME TO C BANK ATM SIMULATOR   \n");
    printf("========================================\n");

    while (running) {
        displayMenu();
        printf("Enter your choice (1-4): ");

        if (scanf("%d", &choice) != 1) {
            printf("Invalid input! Please enter a number between 1 and 4.\n\n");
            while (getchar() != '\n') {
                /* Clear invalid characters from input buffer */
            }
            continue;
        }

        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                balance = depositMoney(balance);
                break;
            case 3:
                balance = withdrawMoney(balance);
                break;
            case 4:
                printf("\nThank you for using C Bank ATM. Have a great day!\n");
                running = 0;
                break;
            default:
                printf("Invalid choice! Please select an option from 1 to 4.\n\n");
                break;
        }
    }

    return 0;
}

void displayMenu(void) {
    printf("\n--- ATM MENU ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");
}

void checkBalance(double balance) {
    printf("\n[Balance Inquiry] Current Account Balance: Rs. %.2f\n", balance);
}

double depositMoney(double balance) {
    double amount;

    printf("\nEnter amount to deposit (Rs.): ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input! Please enter a valid numeric amount.\n");
        while (getchar() != '\n') {
            /* Clear invalid characters from input buffer */
        }
        return balance;
    }

    if (amount <= 0.0) {
        printf("Deposit failed! Amount must be greater than Rs. 0.00.\n");
        return balance;
    }

    balance += amount;
    printf("Deposit successful! Deposited Rs. %.2f.\n", amount);
    printf("Updated Account Balance: Rs. %.2f\n", balance);
    return balance;
}

double withdrawMoney(double balance) {
    double amount;

    printf("\nEnter amount to withdraw (Rs.): ");
    if (scanf("%lf", &amount) != 1) {
        printf("Invalid input! Please enter a valid numeric amount.\n");
        while (getchar() != '\n') {
            /* Clear invalid characters from input buffer */
        }
        return balance;
    }

    if (amount <= 0.0) {
        printf("Withdrawal failed! Amount must be greater than Rs. 0.00.\n");
        return balance;
    }

    if (amount > balance) {
        printf("Withdrawal failed! Insufficient balance (Available: Rs. %.2f).\n", balance);
        return balance;
    }

    balance -= amount;
    printf("Withdrawal successful! Please collect your cash: Rs. %.2f.\n", amount);
    printf("Updated Account Balance: Rs. %.2f\n", balance);
    return balance;
}
