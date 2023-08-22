#include "structs.h"
#include "ssh.h"

/**
 * start - Handle the mode of the shell.
 *
 * @info: Struct containing information about the shell.
 * This function handles the mode of the shell,
 * which can be either INTERACTIVE or NON_INTERACTIVE.
 *
 * It invokes the start_prompt function
 * to initiate the shell's prompt
 * and interaction based on the mode specified in the @info struct.
 **/
void start(general_t *info)
{
	/* Initiate the appropriate shell prompt based on the mode */
	start_prompt(info);
}
