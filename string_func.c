#include "structs.h"
#include "ssh.h"

/**
 * _strlen - Return string length
 * @msg: String to measure
 * Return: Length of the string
 **/
int _strlen(char *msg)
{
	int i;

	for (i = 0; msg[i]; i++)
		;

	return (i);
}

/**
 * _strcat - Concatenate strings
 * @dest: Destination string
 * @src: Source string
 * Return: Concatenated string
 */
char *_strcat(char *dest, char *src)
{
	int len_dest, i;

	len_dest = _strlen(dest);

	for (i = 0; src[i]; i++, len_dest++)
		dest[len_dest] = src[i];

	dest[len_dest] = '\0';

	return (dest);
}

/**
 * _strcpy - Copy strings
 * @dest: Destination string
 * @src: Source string
 * Return: Pointer to the destination string
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i]; i++)
		dest[i] = src[i];

	dest[i] = '\0';

	return (dest);
}

/**
 * _strdup - Duplicate string in memory
 * @str: Source string
 * Return: Pointer to duplicated string
 **/
char *_strdup(char *str)
{
	int size, i;
	char *dest;

	if (!str)
		return (NULL);

	size = _strlen(str) + 1;
	dest = malloc(size * sizeof(char));
	if (!dest)
		return (NULL);

	for (i = 0; i < size; i++)
		dest[i] = str[i];

	return (dest);
}

/**
 * _strcmp - Compare strings
 * @s1: First string
 * @s2: Second string
 * Return: Integer representing comparison result
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i]; i++)
	{
		if (s1[i] != s2[i])
			return (s1[i] - s2[i]);
	}

	return (0);
}
