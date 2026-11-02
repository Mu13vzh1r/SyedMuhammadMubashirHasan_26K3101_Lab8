#include <stdio.h>
int checkEligibility(int age, float salary, float loans){
    if (age >= 21){
        if (salary >= 50000){        
            float percentage = (salary-loans)*100/salary;
            if (percentage >= 40)
                return 1;
            else 
                return 4;
        }
        else
            return 3;
    }    
    else
        return 2; 
    
}

float calcMaxLoan(float salary, float loans){
    float maxLoan = (salary-loans)*10;
    return maxLoan;
}

int main(){
    float salary, loans, newLoan;
    int age, check;
    printf("Enter Age, Monthly Salary, and Existing Monthly Loans: ");
    scanf("%d %f %f", &age, &salary, &loans);

    check = checkEligibility(age, salary, loans);
    switch (check){
        case 1:        
            newLoan = calcMaxLoan(salary, loans);
            printf("\nMaximum Loan Amount: Rs.%.2f", newLoan);
            break;

        case 2:
            printf("\nYou are too young.");
            break;

        case 3:
            printf("\nMonthly Salary is too low.");
            break;

        case 4:
            printf("\nExisting Loans are too high.");
            break;

        default:
            printf("\nError! Unexpected Output.");
    }

    return 0;
    


}