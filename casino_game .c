#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void login() {
    char username[50], password[50];
    char existingUsername[50] = "user123"; // Example existing user
    char existingPassword[50] = "pass123"; // Example existing password

    printf("Are you a new user or an existing user? (new/existing): ");
    char userType[10];
    scanf("%s", userType);

    if (strcmp(userType, "new") == 0) {
        printf("Create a username: ");
        scanf("%s", username);
        printf("Create a password: ");
        scanf("%s", password);
        printf("Account created successfully! Please log in.\n");
    } else if (strcmp(userType, "existing") == 0) {
        printf("Enter your username: ");
        scanf("%s", username);
        printf("Enter your password: ");
        scanf("%s", password);

        if (strcmp(username, existingUsername) == 0 && strcmp(password, existingPassword) == 0) {
            printf("Login successful! Welcome back, %s.\n", username);
        } else {
            printf("Invalid username or password. Please try again.\n");
            exit(1);
        }
    } else {
        printf("Invalid input. Please restart the program.\n");
        exit(1);
    }
}
int main() 
{
    //introduction to the game 

    rules();
    printf("Welcome to the game!\n");
  
    printf("Now, let's start the game!\n");
    round1();

    return 0;
}
int rules() {
    printf("Welcome to the games!\n");
    printf("In this game, you should deposit Money but not below 10000\n");
    printf("You will have to place a maximum of 10 bets\n");
    printf("if you guess the correct ,Number you win the bet amount\n");
    printf("if you guess the wrong number, you lose the bet amount\n");
    printf("Good luck!\n\n\n");
    return 0;
}
int round1() {
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);
    printf("Hello, %s! Let's start the game!\n", name);

    printf("\n\n");

int deposit;
    printf("Enter your deposit amount (minimum 10000): ");
    scanf("%d", &deposit);
    while (deposit < 10000) {
        printf("Deposit amount must be at least 10000. Please enter again: ");
        scanf("%d", &deposit);
    }
    printf("\n\n");
   
    
    printf("Your deposit amount is: %d\n", deposit);

int bet1; 
    printf("Enter your bet amount (maximum 10 bets): ");
    scanf("%d", &bet1);
    while (bet1 > deposit) {
        printf("Bet amount cannot exceed your deposit. Please enter again: ");
        scanf("%d", &bet1);
    }
    printf("\n\n");
    
    printf("Your bet amount is: %d\n", bet1);

    int computer1; 
    computer1 = rand() % 10 + 1; // Random number between 1 and 10

    int guess1;
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guess1);
    while (guess1 < 1 || guess1 > 10) {
        printf("Invalid guess. Please enter a number between 1 and 10: ");
        scanf("%d", &guess1);
    }
    printf("\n\n");

    printf("Your guess is: %d\n", guess1);


    if (guess1 == computer1) {
        printf("Congratulations! You guessed the correct number!\n");
        deposit += bet1; // Add bet amount to deposit
    } else {
        printf("Sorry, you guessed wrong. The correct number was %d.\n", computer1);
        deposit -= bet1; // Subtract bet amount from deposit
    }

    printf("Your new deposit amount is: %d\n", deposit);
    
    return 0;
}