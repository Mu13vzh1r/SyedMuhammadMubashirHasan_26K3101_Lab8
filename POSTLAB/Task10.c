#include <stdio.h>
float calcSubtotal(float price, int quantity){
    return price*quantity;
}

float calcBulkDiscount(float bill){
    if (bill > 5000)
        return bill*0.10;
    else
        return 0;
}

float calcMemberDiscount(float bill, int member){
    if (member == 1)
        return bill*0.05;
    else
        return 0;
}

float calcPaymentFee(float bill, int card){
    if (card == 1)
        return bill*0.02;
    else
        return 0;
}

void displayBill(float subtotal, float bulk, float memberDisc, float fee, float finalAmnt){
    printf("\nSubtotal: Rs. %.2f\n", subtotal);
    if (bulk > 0)
        printf("Bulk Discount: Rs. %.2f\n", bulk);
        
    if (memberDisc > 0)
        printf("Member Discount: Rs. %.2f\n", memberDisc);
        
    if (fee > 0)
        printf("Payment Fee: Rs. %.2f\n", fee);
    printf("Final Payable Amount: Rs. %.2f\n", finalAmnt);
}

int main(){
    float price, subtotal, bulkDiscount, memberDiscount, paymentFee, finalAmount;
    int quantity, member, card;

    printf("Enter product price: ");
    scanf("%f", &price);
    printf("Enter product quantity: ");
    scanf("%d", &quantity);
    printf("Is customer a member? (1 for Yes, 0 for No): ");
    scanf("%d", &member);
    printf("Pay by card? (1 for Yes, 0 for No): ");
    scanf("%d", &card);

    subtotal = calcSubtotal(price, quantity);
    bulkDiscount = calcBulkDiscount(subtotal);
    memberDiscount = calcMemberDiscount(subtotal, member);
    
    finalAmount = subtotal - bulkDiscount - memberDiscount;
    paymentFee = calcPaymentFee(finalAmount, card);
    finalAmount = finalAmount + paymentFee;

    displayBill(subtotal, bulkDiscount, memberDiscount, paymentFee, finalAmount);



    return 0;


}
