// an interactive program that allows a user to guess a number between 1-10
// prints a menu with 3 options:
// 1 to play guessing game
// 2 to change max number
// 3 to quit

// include statements
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// print menu function
void printMenu();

// main method
int main()
{
   int userOption, correctNumber, newMax, maxValue = 10;
   char userGuess[3], numAsString[3];
   time_t t;

   do
   {
      // print menu on screen and accept user input
      printMenu();
      scanf("%d", &userOption);

      // choose number guessing game
      if (userOption == 1)
      {
         // generate random number for guessing game
         srand((unsigned) time(&t));
         correctNumber = (rand() % maxValue + 1);
         // convert random number int to string
         sprintf(numAsString, "%d", correctNumber);

         do
         {
            // prompt user to enter number for guessing game; store as string
            printf("Please guess a number between 1 and %d: ", maxValue);
            scanf("%s", userGuess);

            // compare: if guess is equal to random number
            if (strcmp(userGuess, numAsString) == 0)
            {
               printf("Congrats! You guessed the right number!\n");
               break;
            }
            // compare: if guess is less than random number in ascii
            else if (strcmp(userGuess, numAsString) < 0)
            {
               printf("Too low. Please try again.\n");
            }
            // compare: if guess is greater than random number in ascii
            else if (strcmp(userGuess, numAsString) > 0)
            {
               printf("Too high. Please try again.\n");
            }

           // quit if user enters "q" 
         } while (strcmp(userGuess, "q") != 0);
      }

      // choose to change max value
      if (userOption == 2)
      {
         do
         {
            // prompt user to enter number for max value; store as int
            printf("Please set a new number for the max value: ");
            scanf("%d", &newMax);

            // validate that user value is within boundaries
            if (newMax > 0 && newMax <= maxValue)
            {
               maxValue = newMax;
               printf("Max value set to %d\n", maxValue);
               break;
            }
            else if (newMax <= 0)
            {
               printf("Max value cannot be less than zero. Please try again.\n");
            }
            else if (newMax > maxValue)
            {
               printf("Max value cannot be greater than current max value. "); 
               printf("Please try again.\n");
            }

         } while (newMax <= 0 || newMax > maxValue);  
      }
   } while (userOption != 3);

   // print final message to user
   printf("\nThank you for playing the number guessing game.\n");
   printf("The number guessing game has ended.\n\n");

   return 0;
}

void printMenu()
{
   printf("\nMAIN MENU:\n");
   printf("    Press 1 to play a game\n");
   printf("    Press 2 to change the max number\n");
   printf("    Press 3 to quit\n\n");
   printf("Please enter your option: ");
}
