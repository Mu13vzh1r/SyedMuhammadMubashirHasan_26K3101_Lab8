#include <stdio.h>
float calcBaseCharge(float weight){
    float charge;

    if (weight <= 2) 
        charge = 200;
    else if (weight <= 5)
        charge = 400;
    else
        charge = 700;

    return charge;

}


float calcDistanceCharge(float distance){
    float charge;

    if (distance > 10) 
        charge = (distance - 10)*20.0;
    else
        charge = 0;

    return charge;
    
}

float calcDiscount(float totalCharges, int member){
    if (member == 1 && totalCharges > 1000) {
        return totalCharges * 0.10;
    }
    return 0;
}


int main(){
    float weight, distance, baseCharge, distanceCharge, subTotal, discount, finalAmount;
    int member;
    
    printf("Enter parcel weight: ");
    scanf("%f", &weight);
    printf("Enter delivery distance: ");
    scanf("%f", &distance);
    printf("Is the customer a member? (1 for Yes 0 for No): ");
    scanf("%d", &member);

    baseCharge = calcBaseCharge(weight);
    distanceCharge = calcDistanceCharge(distance);
    
    subTotal = baseCharge + distanceCharge;
    discount = calcDiscount(subTotal, member);
    finalAmount = subTotal - discount;

    printf("\nBase Charges: Rs. %.2f\n", baseCharge);
    printf("Distance Charges: Rs. %.2f\n", distanceCharge);
    printf("Discount: Rs. %.2f\n", discount);
    printf("Final Amount: Rs. %.2f\n", finalAmount);

    return 0;


}
