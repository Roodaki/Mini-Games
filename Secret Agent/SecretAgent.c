#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int difficulty_mode, num_lives;
    int summation, product;
    int summation_guessed, product_guessed;
    int new_digit_guess;

    printf("Hey Secret Agent. Please Choose the Difficulty of the Game: \n1. Easy(10 Lives)\n2. Normal(5 Lives)\n3. Hard(3 Lives)\n4. Legendary(1 Live)\nChosen Mode: ");
    scanf("%d", &difficulty_mode);

    switch (difficulty_mode)
    {
    case 1:
        num_lives = 10;
        break;

    case 2:
        num_lives = 5;
        break;

    case 3:
        num_lives = 3;
        break;

    case 4:
        num_lives = 1;
        break;

    default:
        printf("Invalid Input for the Difficulty Mode. Entered Number Must be Between 1 and 4!\n");
        return 1;
    }

    srand(time(NULL));
    int num1 = (rand() % 10) + 1, num2 = (rand() % 10) + 1, num3 = (rand() % 10) + 1;

    summation = num1 + num2 + num3;
    product = num1 * num2 * num3;

    printf("\nThe Summation and Product of the Password's Digits are %d and %d Respectively!\nNow Try Guessing the Digits\n\n", summation, product);

    while (num_lives > 0)
    {
        summation_guessed = 0;
        product_guessed = 1;

        for (int i = 0; i < 3; i++)
        {
            printf("Agent, Please Guess the %d's Digit: ", i + 1);
            scanf("%d", &new_digit_guess);
            summation_guessed += new_digit_guess;
            product_guessed *= new_digit_guess;
        }

        if (summation_guessed == summation && product_guessed == product)
        {
            printf("\nWell Done Agent. You Cracked the Password!\nYour Country is Now Proud of You!\n\n");
            break;
        }
        else
        {
            num_lives -= 1;
            printf("\nWrong Guess Agent! You Have just %d Lives Left.\n\n", num_lives);
        }
    }

    if (num_lives == 0)
        printf("SHAME. We Lost the Game!\nCorrect Answer was %d, %d and %d.\n\n", num1, num2, num3);

    return 0;
}
