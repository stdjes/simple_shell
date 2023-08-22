#include "ssh.h"

/**
 * _putchar_to_fd - Print a character to fd- file
 * descriptor
 *
 * @c: Character to be printed
 * @fd: Print in that the character
 *
 * Return: Prints 1 when works.
 * On error, -1 is returned, and errno is set appropriately.
 **/
int _putchar_to_fd(char c, int fd)
{
	return (write(fd, &c, 1));
}


/**
 * print_to_fd - Prints a string
 *
 * @msg: Strin to print in file
 * @fd: File to print
 *
 * Return: No of bytes is printed when works
 * On error, -1 is returned, and errno is set.
 **/
int print_to_fd(char *msg, int fd)
{
	int size;

	size = _strlen(msg);

	return (write(fd, msg, size));
}

/**
 * print_err - Prints to STDERR
 *
 * @msg: Message to be print
 *
 * Return: No of bytes printed
 **/
int print_err(char *msg)
{
	return (print_to_fd(msg, STDERR));
}

/**
 * _putchar - Prints to STDOUT
 *
 * @c: Character to be printed
 *
 * Return: Prints 1 when works
 * On error -1
 **/
int _putchar(char c)
{
	return (write(STDOUT, &c, 1));
}

/**
 * print - Prints to STDOUT
 *
 * @msg: Message to be printed
 *
 * Return: Prints no of bytes when works
 * On errror -1, and set the error
 **/
int print(char *msg)
{
	return (print_to_fd(msg, STDOUT));
}
