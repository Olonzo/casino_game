#include <stdio.h>
#include <stdlib.h>

int rules();

int round1();

int main(){

    rules();

    printf("\n\n");

    round1();

    return 0;
}

int round1(){

    char name[50];
    printf("Enter your name : ");
    scanf("%s",name);

    printf("\n\n");

    int deposit;
    printf("Enter the amount of money to deposit for the game : ");
    scanf("%d",&deposit);

    printf("\n\n");

    printf("Your current balance is %d",deposit);

    int bet1;

