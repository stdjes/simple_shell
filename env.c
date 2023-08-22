#include "structs.h"
#include "ssh.h"

/**
 * bin_env - Coding for the env builtin
 *
 * @info: info about shell
 * @arguments: Commands or arguments
 **/
void bin_env(general_t *info, char **arguments)
{
	(void) info;
	(void) arguments;

	get_full_env();
}
