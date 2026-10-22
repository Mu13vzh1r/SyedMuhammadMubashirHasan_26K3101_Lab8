#include <stdio.h>
void welcomeMsg(){
    printf("Welcome! What would you like to buy?\n");
}

void displayMenu(){
    printf("========== SHOPPING MENU ==========\n");
    printf("      1. Milk        - Rs. 250       \n");
    printf("      2. Bread       - Rs. 150       \n");
    printf("      3. Eggs        - Rs. 300       \n");
    printf("      4. Rice        - Rs. 200       \n");
    printf("      5. Butter      - Rs. 400       \n");
    printf("===================================\n");
}

float getPrice(int product, float prices[]){
    return prices[product-1];
}

float calcPrice(float price, int quantity){
    return price*quantity;
}

int checkContinueShopping(){
    int flag = 0;

    printf("Do you want to continue shopping? Press [1] for Yes and [0] for No.\n");
    scanf("%d", &flag);

    return flag;
}

float calcSubtotal(int size, float prices[]){
    float sum = 0;
    for (int i = 0; i<size; i++){
        sum += prices[i];
    }

    return sum;
}

float giveDiscount(float subTotal){
    float discountCriteria = 1500, discount;

    if (subTotal >= discountCriteria)
        discount = 0.05;
    else
        discount = 0;

    return discount;
}

float giveBill(float subTotal, float discount){
    subTotal = subTotal - (subTotal * discount);
    return subTotal;
}

void displayReceipt(float subTotal, int discount, float finalBill, float total_prices[], float prices[], char names[5][50]){
    int quantity;
    printf("------RECEIPT------\n");
    for (int i = 0; i<5; i++){
        if (total_prices[i] > 0){
            quantity = (int)(total_prices[i]/prices[i]);
            printf("%dx %s - Price: %.2f\n", quantity, names[i], prices[i]);
        }
    }

    printf("Total Amount: Rs. %.2f\n", subTotal);
    printf("Discount: %d%%\n", discount);
    printf("Final Bill: Rs. %.2f\n", finalBill);
}
    
int main(){
    int product, quantity, continue_shopping = 1;
    char productNames[5][50] = {{"Milk"}, {"Bread"}, {"Eggs"}, {"Rice"}, {"Butter"}};
    float productPrices[] = {250, 150, 300, 200, 400};
    float totals[] = {0, 0, 0, 0, 0};
    float subTotal, discount, finalBill;
    
    welcomeMsg();
    displayMenu();
    while (continue_shopping == 1){
        printf("Please enter the corresponding number and the quantity: ");
        scanf("%d %d", &product, &quantity);

        totals[product-1] += calcPrice(getPrice(product, productPrices), quantity);

        continue_shopping = checkContinueShopping();
    }

    subTotal = calcSubtotal(5, totals);
    discount = giveDiscount(subTotal);
    finalBill = giveBill(subTotal, discount);

    displayReceipt(subTotal, (int)(discount*100), finalBill, totals, productPrices, productNames);
    

}