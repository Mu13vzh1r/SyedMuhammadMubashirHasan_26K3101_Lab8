#include <stdio.h>
void checkPalindrome(int num){
    int digit = 1, reversedNum = 0, testNum;
    testNum = num;

    while (testNum > 0){
        digit = testNum%10;
        reversedNum = (reversedNum*10) + digit;
        testNum/=10;
    }

    if (reversedNum == num)
        printf("This number is a palindrome.\n");
    else
        printf("This number is not a palindrome.\n");

}

void checkPrime(int num){
    int primeFlag = 0;
    for (int i=2; i*i<=num; i++){
        if (num%i == 0){
            primeFlag = 1;
            break;
        }
    }
    if (primeFlag == 0 && num != 1)
        printf("This is a prime number.\n");
    else
        printf("This is not a prime number.\n");
}


int main(){
    int num;
    do{
        printf("Enter your number: ");
        scanf("%d", &num);
    }while(num<=0);

    if (num%2 == 0)
        printf("This is an even number.\n");
    else    
        printf("This is an odd number.\n");
    checkPalindrome(num);
    checkPrime(num);

    return 0;
}