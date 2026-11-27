#include <stdio.h>

int main() {
    int choice;
    float balance = 32500.00, amount;

    printf("================================\n");
    printf("       WELCOME TO ATM\n");
    printf("================================\n");

    do {
        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Exit");

        printf("\n\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {

            case 1:
                printf("\nYour balance is: Rs. %.2f\n", balance);
                break;

            case 2:
                printf("\nEnter amount to deposit: Rs. ");
                scanf("%f", &amount);

                if(amount > 0) {
                    balance += amount;
                    printf("\nMoney deposited successfully!");
                    printf("\nUpdated balance: Rs. %.2f\n", balance);
                } else {
                    printf("\nInvalid amount!\n");
                }
                break;

            case 3:
                printf("\nEnter amount to withdraw: Rs. ");
                scanf("%f", &amount);

                if(amount <= 0) {
                    printf("\nInvalid amount!\n");
                }
                else if(amount > balance) {
                    printf("\nInsufficient balance!\n");
                }
                else {
                    balance -= amount;
                    printf("\nPlease collect your cash.");
                    printf("\nRemaining balance: Rs. %.2f\n", balance);
                }
                break;

            case 4:
                printf("\nThank you for using our ATM!");
                printf("\nPlease visit again.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 4);

    return 0;
}
