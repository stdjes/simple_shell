#include "ssh.h"

/**
 * execute - Execute a command in a separate process.
 *
 * @command: Command to execute.
 * @arguments: Arguments of the @command.
 * @info: General information about the shell.
 * @buff: Line read.
 *
 * This function forks a child process to execute the given command with its arguments.
 * It also handles cleanup and error handling in case of execution failure.
 **/
void execute(char *command, char **arguments, general_t *info, char *buff)
{
    int status;
    pid_t pid;

    pid = fork();
    if (pid == 0)
    {
        execve(command, arguments, environ);
        perror("./sh"); // Print error message

        free_memory_pp((void *)arguments);

        if (info->value_path != NULL)
        {
            free(info->value_path);
            info->value_path = NULL;
        }

        free(info);
        free(buff);
        exit(1); // Exit child process
    }
    else if (pid > 0)
    {
        waitpid(pid, &status, 0);
        if (WIFEXITED(status))
            info->status_code = WEXITSTATUS(status);
    }
}

/**
 * current_dir - Execute the command if it's in the current directory.
 *
 * @cmd: Command to execute.
 * @arguments: Arguments of the @cmd.
 * @buff: Line read.
 * @info: General info about the shell.
 *
 * Return: Status of the operation (TRUE or FALSE).
 *
 * This function checks if the command is in the current directory and executable.
 * If conditions are met, it executes the command and returns TRUE.
 **/
int current_dir(char *cmd, char **arguments, char *buff, general_t *info)
{
    if (info->is_current_path == _FALSE)
        return (_FALSE); // Command not in current directory order

    if (is_executable(cmd) == PERMISSIONS)
    {
        execute(cmd, arguments, info, buff);
        return (_TRUE); // Executed from current directory
    }

    return (_FALSE); // Not executed from current directory
}
