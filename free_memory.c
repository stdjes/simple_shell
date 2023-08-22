#include "ssh.h"

/**
 * free_memory_p - Frees a single pointer and sets it to NULL.
 *
 * @ptr: Pointer to be freed and set to NULL.
 *
 * This function frees the memory pointed to by @ptr and sets it to NULL to
 * prevent any potential use-after-free issues.
 **/
void free_memory_p(void *ptr)
{
	if (ptr != NULL)
	{
		free(ptr);
		/* Set the pointer to NULL to avoid dangling pointers */
		ptr = NULL;
	}

	/* Ensure that the pointer outside the function scope is also NULL */
	ptr = NULL;
}

/**
 * free_memory_pp - Frees a double pointer and its contents.
 *
 * @ptr: Double pointer to be freed along with its contents.
 *
 * This function iterates through the array of pointers pointed to by @ptr
 * and frees each individual pointer using the free_memory_p function.
 * Finally, it frees the memory occupied by the double pointer itself.
 **/
void free_memory_pp(void **ptr)
{
	void **tmp;

	for (tmp = ptr; *tmp != NULL; tmp++)
		/* Free the memory pointed to by each element */
		free_memory_p(*tmp);

	/* Free the memory of the double pointer itself */
	free_memory_p(ptr);
}
