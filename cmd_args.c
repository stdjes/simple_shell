#include "ssh.h"

/**
 * analyze - Analyze the arguments passed and execute corresponding actions.
 *
 * @arguments: Array of commands and arguments to be executed
 * @info: Pointer to general information about the shell
 * @buff: Input line read from the shell
 *
 * This function analyzes the provided command and arguments, checks if
 * it's a built-in command, a file with execute permissions, or a command
 * available in the system's PATH. It then performs the appropriate action
 * based on the analysis.
 **/
void analyze(char **arguments, general_t *info, char *buff)
{
	char *cmd;
	int status;

	if (*arguments == NULL || arguments == NULL)
		return;

	cmd = arguments[0];
	info->command = cmd;
	/* Check if the command is a built-in command */
	if (check_builtin(info, arguments) == _TRUE)
		return;
	/* Check if the command is a file and has execute permissions */
	status = is_file(cmd);
	if (status == NON_PERMISSIONS)
	{
		info->status_code = 126;
		info->error_code = _CODE_EACCES;
		error(info);
		return;
	}
	if (status == 1)
	{
		execute(cmd, arguments, info, buff);
		return;
	}
	/* Check if the command is in the current directory */
	if (current_dir(cmd, arguments, buff, info) == _TRUE)
		return;
	/* Look for the command in the PATH and execute if found */
	info->value_path = which(cmd, info);
	if (info->value_path != NULL)
	{
		execute(info->value_path, arguments, info, buff);
		free_memory_p((void *) info->value_path);
		return;
	}
	/* Command not found */
	info->status_code = 127;
	info->error_code = _CODE_CMD_NOT_EXISTS;
	error(info);
}
