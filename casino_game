#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERS 100
#define FILENAME "users.txt"

typedef struct {
    char username[50];
    char password[50];
    int deposit;
} User;

int rules();
int round1(User *currentUser);
void registerUser();
User *loginUser();
void saveUser(User *user);

int main()
{
    rules();

    printf("\nWelcome to the Casino!\n");
    printf("=========================\n\n");

    while (1)
    {
        int choice;
        printf("1. Register\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        if (choice == 1)
        {
            registerUser();
        }
        else if (choice == 2)
        {
            User *currentUser = loginUser();
            if (currentUser != NULL)
            {
                round1(currentUser);
                free(currentUser); // Free memory allocated for the user
            }
        }
        else if (choice == 3)
        {
            printf("Goodbye!\n");
            break;
        }
        else
        {
            printf("Invalid choice. Please try again.\n");
        }
    }

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

void registerUser()
{
    FILE *file = fopen(FILENAME, "a");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    User newUser;
    printf("Enter a username: ");
    scanf("%s", newUser.username);
    printf("Enter a password: ");
    scanf("%s", newUser.password);
    printf("Enter your deposit amount: $");
    scanf("%d", &newUser.deposit);

    while (newUser.deposit <= 0)
    {
        printf("Invalid deposit amount. Please enter a positive amount: $");
        scanf("%d", &newUser.deposit);
    }

    fprintf(file, "%s %s %d\n", newUser.username, newUser.password, newUser.deposit);
    fclose(file);

    printf("Registration successful! You can now log in.\n");
}

User *loginUser()
{
    FILE *file = fopen(FILENAME, "r");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return NULL;
    }

    char username[50], password[50];
    printf("Enter your username: ");
    scanf("%s", username);
    printf("Enter your password: ");
    scanf("%s", password);

    User *currentUser = malloc(sizeof(User));
    while (fscanf(file, "%s %s %d", currentUser->username, currentUser->password, &currentUser->deposit) != EOF)
    {
        if (strcmp(currentUser->username, username) == 0 && strcmp(currentUser->password, password) == 0)
        {
            fclose(file);
            printf("Login successful! Your current deposit is $%d.\n", currentUser->deposit);
            return currentUser;
        }
    }

    fclose(file);
    free(currentUser);
    printf("Invalid username or password. Please try again.\n");
    return NULL;
}

void saveUser(User *user)
{
    FILE *file = fopen(FILENAME, "r+");
    if (file == NULL)
    {
        printf("Error opening file.\n");
        return;
    }

    User tempUser;
    long pos;
    while ((pos = ftell(file)) >= 0 && fscanf(file, "%s %s %d", tempUser.username, tempUser.password, &tempUser.deposit) != EOF)
    {
        if (strcmp(tempUser.username, user->username) == 0)
        {
            fseek(file, pos, SEEK_SET);
            fprintf(file, "%s %s %d\n", user->username, user->password, user->deposit);
            fclose(file);
            return;
        }
    }

    fclose(file);
}

int round1(User *currentUser)
{
    while (currentUser->deposit > 0)
    {
        int bet1;
        printf("Enter your bet amount: $");
        scanf("%d", &bet1);

        while (bet1 > currentUser->deposit || bet1 <= 0)
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
            printf("🎉 Congratulations! You guessed the correct number (%d).\n", computer1);
            printf("You win $%d!\n", bet1 * 2);
            currentUser->deposit += (bet1 * 2);
        }
        else
        {
            printf("😞 Sorry. You guessed %d, but the correct number was %d.\n", guess1, computer1);
            printf("You lose $%d.\n", bet1);
            currentUser->deposit -= bet1;
        }

        printf("\nYour current balance is: $%d\n", currentUser->deposit);
        printf("=====================================\n\n");

        if (currentUser->deposit <= 0)
        {
            printf("You have run out of money. Game over!\n");
            break;
        }

        int decision;
        printf("Do you want to play again? (1 for yes, 0 to quit): ");
        scanf("%d", &decision);

        while (decision != 1 && decision != 0)
        {
            printf("Invalid input. Please enter 1 to play again or 0 to quit: ");
            scanf("%d", &decision);
        }

        if (decision == 0)
        {
            printf("\nThank you for playing! Your final balance is $%d.\n", currentUser->deposit);
            saveUser(currentUser); // Save the updated deposit
            printf("Goodbye!\n");
            break;
        }

        printf("\nLet's play another round!\n");
        printf("=====================================\n\n");
    }

    return 0;
}
