
#include <stdio.h>
#include <stdlib.h> // For rand()

int rules();
int round1();

int main()
{
    rules();

    printf("\nWelcome to the Casino!\n");
    printf("=========================\n\n");

    round1();

    return 0;
}

int rules()
{
    printf("=====================================\n");
    printf("            Casino Rules             \n");
    printf("=====================================\n");
    printf("1. You start with your own deposit.\n");
    printf("2. You can bet any amount.\n");
    printf("3. If you lose, you lose your bet.\n");
    printf("4. The game ends when you run out of money or choose to quit.\n");
    printf("=====================================\n\n");

    return 0;
}

int round1()
{
    char name[50];
    printf("Enter your name: ");
    scanf("%s", name);

    printf("\nHello, %s! Let's start the game.\n", name);
    printf("=====================================\n\n");

    int deposit;
    printf("Enter your deposit amount: $");
    scanf("%d", &deposit);

    while (deposit <= 0)
    {
        printf("Invalid deposit amount. Please enter a positive amount: $");
        scanf("%d", &deposit);
    }

    printf("\nYour deposit amount is: $%d\n", deposit);
    printf("=====================================\n\n");

    while (deposit > 0)
    {
        int bet1;
        printf("Enter your bet amount: $");
        scanf("%d", &bet1);

        while (bet1 > deposit || bet1 <= 0)
        {
            printf("Invalid bet amount. You cannot bet more than your deposit or less than $1.\n");
            printf("Please enter a valid bet amount: $");
            scanf("%d", &bet1);
        }

        printf("\nYou bet $%d. Good luck!\n", bet1);
        printf("=====================================\n\n");

        int computer1 = rand() % 10;

        int guess1;
        printf("Guess a number between 0 and 9: ");
        scanf("%d", &guess1);

        while (guess1 < 0 || guess1 > 9)
        {
            printf("Invalid guess. Please enter a number between 0 and 9: ");
            scanf("%d", &guess1);
        }

        printf("\nThe computer's number is being generated...\n");
        printf("=====================================\n\n");

        if (guess1 == computer1)
        {
            printf("🎉 Congratulations, %s! You guessed the correct number (%d).\n", name, computer1);
            printf("You win $%d!\n", bet1 * 2);
            deposit += (bet1 * 2);
        }
        else
        {
            printf("😞 Sorry, %s. You guessed %d, but the correct number was %d.\n", name, guess1, computer1);
            printf("You lose $%d.\n", bet1);
            deposit -= bet1;
        }

        printf("\nYour current balance is: $%d\n", deposit);
        printf("=====================================\n\n");

        if (deposit <= 0)
        {
            printf("You have run out of money. Game over!\n");
            break;
        }

        int decision;
        printf("Do you want to play again? (1 for yes, 0 for no): ");
        scanf("%d", &decision);

        while (decision != 1 && decision != 0)
        {
            printf("Invalid input. Please enter 1 to play again or 0 to quit: ");
            scanf("%d", &decision);
        }

        if (decision == 0)
        {
            printf("\nThank you for playing, %s! Your final balance is $%d.\n", name, deposit);
            printf("Goodbye!\n");
            break;
        }

        printf("\nLet's play another round!\n");
        printf("=====================================\n\n");
    }

    return 0;
}
