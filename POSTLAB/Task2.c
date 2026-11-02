#include <stdio.h>

int main(){
    int products[2][3][4] = {
        {
            {12, 10, 5, 9},
            {1, 3, 2, 4},
            {8, 7, 14, 15}
        },
        {
            {7, 5, 10, 8},
            {1, 0, 2, 1},
            {16, 12, 13, 11}
        }
    };

    int i, j, k, totalBranch = 0, totalEach = 0, highestSalesPerBranch = 0, mostSoldProduct;
    int highestSalesWeek = 0, mostSoldBranch, highestTotalBranch = 0, mostSoldWeek;

    for (i = 0; i < 2; i++){
        for (j = 0; j < 3; j++){
            for (k = 0; k < 4; k++){
                totalEach += products[i][j][k];
            }
            
            printf("Total Quantity Sold for Product %d, Branch %d: %d\n", j + 1, i + 1, totalEach);
            
            if (highestSalesPerBranch < totalEach){
                highestSalesPerBranch = totalEach;
                mostSoldProduct = j + 1;
            }
            
            totalBranch += totalEach;
            totalEach = 0;
        }
        
        printf("Product %d has the highest sales in Branch %d\n", mostSoldProduct, i + 1);
        mostSoldProduct = 0;
        highestSalesPerBranch = 0;

        if (totalBranch > highestTotalBranch){
            highestTotalBranch = totalBranch;
            mostSoldBranch = i + 1;
        }
        
        totalBranch = 0;
    }
    
    printf("Branch %d sold the most products\n", mostSoldBranch);

    for (k = 0; k < 4; k++){
        for (i = 0; i < 2; i++){
            for (j = 0; j < 3; j++){
                totalEach += products[i][j][k];
            }
        }
        
        if (totalEach > highestSalesWeek){
            highestSalesWeek = totalEach;
            mostSoldWeek = k + 1;
        }
        
        totalEach = 0;
    }

    printf("Highest Sales Week is Week %d with %d Sales\n", mostSoldWeek, highestSalesWeek);

    return 0;
}
