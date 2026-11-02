#include <stdio.h>
void displayMenu(){
    printf("\n--- ATM Menu ---\n");
    printf("1. Check Balance\n");
    printf("2. Deposit Money\n");
    printf("3. Withdraw Money\n");
    printf("4. Exit\n");

}

void checkBalance(float balance){
    printf("Current Balance: Rs. %.2f\n", balance);
}

float depositMoney(float balance){
    float amount;
    printf("Enter deposit amount: ");
    scanf("%f", &amount);

    if (amount > 0) {
        balance += amount;
        printf("Successfully deposited. New Balance: Rs. %.2f\n", balance);
    } 
    else 
        printf("Invalid deposit amount.\n");


    return balance;
}

float withdrawMoney(float balance){
    float amount;
    printf("Enter withdrawal amount: ");
    scanf("%f", &amount);

    if (amount <= 0)
        printf("Invalid withdrawal amount.\n");
    else if (amount > 10000)
        printf("Withdrawal limit exceeded. Maximum Rs. 10000 allowed per transaction.\n");
    else if (amount > balance)
        printf("Insufficient balance.\n");
    else {
        balance -= amount;
        printf("Successfully withdrawn. New Balance: Rs. %.2f\n", balance);
        
        if (balance < 5000)
            printf("Warning: Low balance!\n");

    }

    return balance;
}

int main(){
    float balance = 20000;
    int choice = 0;

    while (choice != 4) {
        displayMenu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice){
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
                printf("Thank you for using the ATM. Have a nice day.\n");
                break;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }

    return 0;




}
