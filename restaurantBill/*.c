// this program computes the tax and tip on a restaurant bill for a patron
// accepts the tax and tip both as percentages from command line
// displays the meal cost, tax amount, and total bill on the screen
// meal cost chosen randomly from 4 options

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
   // initialize variables
   time_t t;
   double menu[4] = {9.95, 4.55, 13.25, 22.35};
   double mealCost = 0, totalBill = 0;
   double taxPercentage, tipPercentage;
   
   // display menu on screen
   printf("Menu:\n");
   printf("\tSalad: $9.95\n");
   printf("\tSoup: $4.55\n");
   printf("\tSandwich: $13.25\n");
   printf("\tPizza: $22.35\n\n");

   // ask user to enter tax percent
   printf("Please enter a tax amount: ");
   scanf("%lf", &taxPercentage);
   // ask user to enter tip percent
   printf("Please enter a tip amount: ");
   scanf("%lf", &tipPercentage);

   // initialize random number generator
   srand((unsigned) time(&t));
   // assign meal cost to menu at index of random number
   mealCost = menu[rand() % 5];

   // print cost, tax, tip, and total to screen
   printf("\nCost: $%.2f\n", mealCost);
   printf("Tax amount: $%.2f\n", mealCost * taxPercentage / 100);
   printf("Tip amount: $%.2f\n", mealCost * tipPercentage / 100);
   printf("Total bill: $%.2f\n\n", mealCost + (mealCost * taxPercentage / 100)
                                   + (mealCost * tipPercentage / 100));

   return 0;
}
