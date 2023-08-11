#include <stdio.h>
#include <stdlib.h>

long long int product(long int a, long int b);

/**
 * main - Multiply two numbers.
 *
 * Return: The product of a and b.
 */


int main(void)
{
	long int x, y;
	long long int prod;
	char check;

	/* Prompt user for input */
	printf("I will multiply any two numbers you enter.\n");
	printf("Enter (Y) to proceed, (N) to quit.\n");
	scanf("%c", &check);

	/* Check user's choice */
	if (check == 'N' || check == 'n')
	{
		printf("Okay, have a nice day\n");
		exit(0);
	}
	else if (check == 'Y' || check == 'y')
	{
		/* Get user input for numbers */
		printf("Enter first Number: ");
		scanf("%ld", &x);
		printf("Enter second Number: ");
		scanf("%ld", &y);

		/* Calculate and display product */
		prod = product(x, y);
		printf("The product is %lld\n", prod);
	}
	else
	{
		/* Invalid input */
		printf("Invalid input\n");
		printf("Okay Bye.\n");
	}

	return (0);
}

/**
 * product - Multiply two numbers.
 * @a: First number.
 * @b: Second number.
 *
 * Return: The product of a and b.
 */
long long int product(long int a, long int b)
{
	/* Calculate and return the product */
	return (a * b);
}

