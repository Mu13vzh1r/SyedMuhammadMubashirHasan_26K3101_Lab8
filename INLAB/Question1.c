#include <stdio.h>
void welcome(){
    printf("Welcome!\n");
}
void displayAmount(float amount){
    printf("Amount Withdrawn: Rs. %.2f\n", amount);
}
float getWithdrawalLimit(){
    float limit = 50000;
    return limit;
}
float calculateBalance(float currBalance, float withAmount){
    float remBalance = currBalance-withAmount;
    return remBalance;
}
int checkWithdrawal(float currBalance, float withAmount, float maxLimit){
    if (withAmount > 0 && withAmount <= currBalance && withAmount <= maxLimit)
        return 1;
    else
        return 0;
}

int main(){
    float withdrawal, accountBal;
    int check;
    welcome();
    printf("Enter account balance: ");
    scanf("%f", &accountBal);
    printf("Enter withdrawal amount: ");
    scanf("%f", &withdrawal);

    printf("\n");
    check = checkWithdrawal(accountBal, withdrawal, getWithdrawalLimit());
    if (check == 1){
        accountBal = calculateBalance(accountBal, withdrawal);
        displayAmount(withdrawal);
        printf("Remaining Balance: Rs. %.2f\n", accountBal);
    }
    else
        printf("Invalid withdrawal amount.");
}
