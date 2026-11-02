#include <stdio.h>

float billCalculator(int units, int customer){
    float bill = 0;
    
    if (customer == 1){
        if (units > 100) {
            bill = 15.0 * 100 + (units - 100) * 20.0;
        } else {
            bill = 15.0 * units;
        }
    } else {
        bill = 25.0 * units;
    }
    
    return bill;
}

float discountCalc(float bill){
    float surcharge = bill * 0.05;
    return surcharge;
}

int main(){
    int units, customerType;
    float billAmount, surcharge = 0, finalBill;

    printf("Enter the Units consumed: ");
    scanf("%d", &units);
    
    printf("Enter 1 if you are a Domestic Customer or 2 if you are a Commercial customer: ");
    scanf("%d", &customerType);

    billAmount = billCalculator(units, customerType);

    if (billAmount > 5000) {
        surcharge = discountCalc(billAmount);
    }

    finalBill = billAmount + surcharge;

    printf("Units Consumed: %d\nBill Amount: Rs. %.2f\nSurcharge: Rs. %.2f\nFinal Payable Amount: Rs. %.2f\n", units, billAmount, surcharge, finalBill);

    return 0;
}
