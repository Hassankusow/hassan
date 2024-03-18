// hassan abdi  
// cs205
// final project
// 3/1/2024

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    char secretCode[7]; // 6 digits + '\0'
    char userGuess[7]; // 6 digits + '\0'
    char feedback[7]; // Feedback for each position

    srand(time(NULL));

    // Generate secret code
    for (int i = 0; i < 6; i++) {
        secretCode[i] = "0123456789abcdef"[rand() % 16];
    }
    secretCode[6] = '\0';

    printf("Welcome to Mastermind!\n");
    printf("Try to guess the 6-digit hexadecimal code.\n");
    printf("Enter your guess (6 hexadecimal digits): ");

    int attempts = 0;
    while (attempts < 20) { // Limit to 20 attempts
        scanf("%6s", userGuess); // Read user input

        // Compare guess with secret code and provide feedback
        for (int i = 0; i < 6; i++) {
            if (userGuess[i] == secretCode[i]) {
                feedback[i] = 'x'; // Correct digit in correct position
            } else if (strchr(secretCode, userGuess[i]) != NULL) {
                feedback[i] = 'o'; // Correct digit in wrong position
            } else {
                feedback[i] = ' '; // Incorrect digit
            }
        }
        feedback[6] = '\0'; // Null-terminate the string

        printf("Feedback: %s\n", feedback);

        // Check if guess is correct using strcmp
        if (strcmp(userGuess, secretCode) == 0) {
            printf("Congratulations! You guessed the code: %s\n", secretCode);
            break;
        } else {
            printf("Try again.\n");
            attempts++;
        }
    }

    if (attempts == 20) {
        printf("You have reached the maximum number of attempts. The correct code was: %s\n", secretCode);
    }

    return 0;
}
