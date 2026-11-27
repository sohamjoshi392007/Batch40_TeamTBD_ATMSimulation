#include <stdio.h>

int main() {
    int choice, mpin = 1234, enteredPin;
    int newPin, confirmPin, attempts = 3;
    float balance = 32500.00, amount;

    printf("================================\n");
    printf("       WELCOME TO ATM\n");
    printf("================================\n");

    // MPIN Login
    while(attempts > 0) {
        printf("\nEnter your 4-digit MPIN: ");
        scanf("%d", &enteredPin);

        if(enteredPin == mpin) {
            printf("\nLogin Successful!\n");
            break;
        }
        else {
            attempts--;
            printf("\nIncorrect MPIN!");
            printf("\nAttempts remaining: %d\n", attempts);
        }
    }

    if(attempts == 0) {
        printf("\nATM BLOCKED! Too many incorrect attempts.\n");
        return 0;
    }

    // ATM Menu
    do {
        printf("\n================================");
        printf("\n           ATM MENU");
        printf("\n================================");

        printf("\n1. Check Balance");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Change MPIN");
        printf("\n5. Exit");

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
                }
                else {
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
                printf("\nEnter your current MPIN: ");
                scanf("%d", &enteredPin);

                if(enteredPin == mpin) {

                    printf("\nEnter new 4-digit MPIN: ");
                    scanf("%d", &newPin);

                    if(newPin >= 1000 && newPin <= 9999) {

                        printf("\nConfirm new MPIN: ");
                        scanf("%d", &confirmPin);

                        if(newPin == confirmPin) {
                            mpin = newPin;
                            printf("\nMPIN changed successfully!\n");
                        }
                        else {
                            printf("\nMPIN does not match!\n");
                        }
                    }
                    else {
                        printf("\nMPIN must contain exactly 4 digits!\n");
                    }
                }
                else {
                    printf("\nIncorrect current MPIN!\n");
                }
                break;

            case 5:
                printf("\nThank you for using our ATM!");
                printf("\nPlease visit again.\n");
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }

    } while(choice != 5);

    return 0;
}
