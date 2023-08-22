#include "ssh.h"

/**
 * digits - Count the number of digits in an integer.
 *
 * @n: Number for which to count the digits.
 *
 * Return: Number of digits in the integer.
 *
 * This function calculates and returns the count of digits in the integer @n.
 **/
int digits(int n)
{
	int i;

	for (i = 0; n != 0; i++, n /= 10)
		;

	return (i);
}

/**
 * to_string - Convert an integer to a string.
 *
 * @number: Integer to convert.
 *
 * Return: String representation of the integer.
 *
 * This function converts an integer @number to its string representation.
 * The resulting string is dynamically allocated.
 **/
char *to_string(int number)
{
	int n_digits, i;
	char *_number;

	n_digits = digits(number);
	_number = malloc(n_digits * sizeof(char) + 2);
	if (number == 0)
	{
		_number[0] = '0';
		_number[1] = '\0';
		return (_number);
	}

	_number[n_digits] = '\0';
	for (i = n_digits - 1; number != 0; number /= 10, i--)
		_number[i] = (number % 10) + '0';

	return (_number);
}

/**
 * is_numerical - Check if a character is a digit.
 *
 * @n: Character to check.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 *
 * This function checks if the given character @n is a numerical digit
 * i.e ranging from ('0' - '9').
 **/
int is_numerical(unsigned int n)
{
	return (n >= '0' && n <= '9');
}

/**
 * _atoi - Convert a string to an integer.
 *
 * @s: String to convert.
 *
 * Return: Converted integer.
 *
 * This function converts a string @s to an integer.
 * It processes both positive and negative numbers.
 **/
int _atoi(char *s)
{
	unsigned int number, i;
	int sign;

	sign = 1;
	number = 0;
	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]))
		{
			number = (s[i] - 48) + number * 10;

			if (s[i + 1] == ' ')
				break;
		}
		else if (s[i] == '-')
		{
			sign *= -1;
		}
	}

	return (number * sign);
}

/**
 * contains_letter - Search non-digits in a string.
 *
 * @s: String to search.
 *
 * Return: _TRUE if a non-digit was found, _FALSE otherwise.
 *
 * This function searches for non-digit characters in the given string @s.
 * If it finds any non-digit character,
 * it returns _TRUE; otherwise, it returns _FALSE.
 **/
int contains_letter(char *s)
{
	int i;

	for (i = 0; s[i] != '\0'; i++)
	{
		if (is_numerical(s[i]) == _FALSE)
			return (_TRUE);
	}

	return (_FALSE);
}
