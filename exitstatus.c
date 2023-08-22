#include "ssh.h"

/**
 * bin_exit - Coding of the exit builtin
 * Description: Release all the memory used and
 * exit with the last status_code
 *
 * @info: Info about the shell
 * @arguments: Arguments
 **/
void bin_exit(general_t *info, char **arguments)
{
	int status_code, status;

	status = _TRUE;
	if (arguments[1] != NULL)
		status = number_controller(info, arguments[1]);

	if (status == _FALSE)
		return;

	status_code = info->status_code;

	free_memory_pp((void **) arguments);
	free_memory_p((void *) info->buffer);
	free_memory_p((void *) info->environment);
	free_memory_p((void *) info);

	exit(status_code);
}

/**
 * number_controller - Controls the args of exit
 * @info: Info  about the shell
 * @number: The argument of the builtin
 *
 * Return: If the argument is valid, return _TRUE
 * if not, return _FALSE
 **/
int number_controller(general_t *info, char *number)
{
	int _number;

	_number = _atoi(number);

	if (_number < 0 || contains_letter(number))
	{
		info->status_code = 2;
		info->error_code = _CODE_ILLEGAL_NUMBER;
		error_extra(info, number);
		return (_FALSE);
	}

	if (_number > 255)
		info->status_code = _number % 256;
	else
		info->status_code = _number;

	return (_TRUE);
}
