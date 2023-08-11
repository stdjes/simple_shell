#include <stdio.h>
#include <stdlib.h>
long long int product(long int a, long int b);

int main(void)
{	long int x, y;
	long long int prod;
	char check;

	printf("I will multiply any two numbers you enter.\n");
	printf("Enter (Y) to proceed, (N) to quit.\n");
	scanf("%c",&check);
	if ( check == 'N' || check == 'n' )
	{	printf("Okay, have a nice day\n");
		exit(0);
	}
	else if (check == 'Y'|| check == 'y')
	{	
		printf("Enter first Number: ");
		scanf("%ld", &x);
		printf("Enter second Number: ");
		scanf("%ld", &y);

		prod = product(x , y);
		printf("The product is %lld \n", prod);
	}
	else
	{
		printf("Invalid input\n");
		printf("Okay Bye.\n");
	}

	return(0);	
}

long long int product(long int a, long int b)
{
	long long int mult;

	mult = a * b;
	return (mult);
}
