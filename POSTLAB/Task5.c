#include <stdio.h>
float calcBonus(float salary, int years){
    float bonus;
    if (years > 5)
        bonus = 0.15;
    else if (years > 2)
        bonus = 0.10;
    else
        bonus = 0.05;

    return (bonus*salary);
}

float calcTax(float salary){
    float tax;
    if (salary > 100000)
        tax = salary*0.05;

    return tax;
}


int main(){
    float salary, tax, bonus, finalSalary;
    int years;

    printf("Enter Basic Salary and Years of Service: ");
    scanf("%f %d", &salary, &years);

    bonus = calcBonus(salary, years);
    finalSalary = salary + bonus;
    tax = calcTax(finalSalary);
    finalSalary -= tax;

    printf("Basic Salary [Rs.%.2f]\nBonus [Rs.%.2f]\nTax Deducted [Rs.%.2f]\n\nFinal Salary[Rs.%.2f]", salary, bonus, tax, finalSalary);
    
}