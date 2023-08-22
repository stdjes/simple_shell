#include "structs.h"
#include "ssh.h"

/**
 * analyze_patterns - Analyzes patterns using pattern_handler.
 * @info: Pointer to general information structure.
 * @arguments: Double pointer to array of arguments for analysis.
 */

void analyze_patterns(general_t *info, char **arguments)
{
	int i;

	for (i = 0; arguments[i] != NULL; i++)
		arguments[i] = pattern_handler(info, arguments[i]);
}

/**
 * pattern_handler - Handles pattern replacement in a string.
 * @info: Pointer to general information structure.
 * @string: Input string to process for pattern replacement.
 * Return: Pointer to modified string after pattern handling.
 */

char *pattern_handler(general_t *info, char *string)
{
	int i;

	for (i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == '$' && string[i + 1] != '\0')
			string = replace_value(info, &i, string);
	}

	return (string);
}

/**
 * replace_value - Replaces pattern with corresponding value.
 * @info: Pointer to general information structure.
 * @index: Pointer to current index in the string.
 * @string: Input string containing the pattern.
 * Return: Pointer to modified string after replacement.
 */

char *replace_value(general_t *info, int *index, char *string)
{
	int i, new_s, old_s;
	char *value;

	i = *index;
	i++;

	value = replacement(info, index, string + i);
	if (value == NULL)
	{
		string = _strcpy(string, "");
		return (string);
	}

	old_s = _strlen(string);
	new_s = _strlen(value) + 1;

	string = _realloc(string, old_s, new_s);
	string = _strcpy(string, value);

	free_memory_p(value);
	*index = i;
	return (string);
}

/**
 * replacement - Generates replacement value based on given symbol.
 * @info: Pointer to general information structure.
 * @index: Pointer to current index in the string (unused).
 * @string: String containing symbol and optional argument.
 * Return: Pointer to generated replacement value.
 */

char *replacement(general_t *info, int *index, char *string)
{
	char *tmp;
	char symbol;

	(void) index;

	symbol = *string;
	if (symbol != '?' && symbol != '$')
	{
		tmp = replace_env(info, string);
		return (tmp);
	}

	tmp = (symbol == '$') ? to_string(info->pid) :
		to_string(info->status_code);

	return (tmp);
}

/**
 * replace_env - Retrieves environment variable's value.
 * @info: Pointer to general information structure (unused).
 * @environment: Name of the environment variable.
 * Return: Pointer to the value of the environment variable.
 */

char *replace_env(general_t *info, char *environment)
{
	char *env;

	(void) info;

	env = _getenv(environment);
	if (env != NULL)
		return (env);

	return (NULL);
}
