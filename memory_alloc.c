#include "ssh.h"

/**
 * _realloc - Reallocate a memory block using malloc and free.
 *
 * @ptr: Pointer to the memory previously allocated.
 * @old_size: Size, in bytes, of the allocated space for @ptr.
 * @new_size: New size, in bytes, of the new memory block.
 *
 * Return: Memory reallocated, or NULL on failure.
 *
 * This function reallocates a memory block pointed to
 * by @ptr, changing its size to @new_size.
 * If @ptr is NULL, it behaves like malloc
 * and allocates a new memory block of size @new_size.
 * If @new_size is 0 and @ptr is not NULL,
 * the memory block is freed and NULL is returned.
 * If reallocation fails, NULL is returned,
 * and the original block is unchanged.
 **/
void *_realloc(void *ptr, size_t old_size, size_t new_size)
{
	char *s, *aux;
	unsigned int a;

	if (new_size == old_size)
		return (ptr); /* No change needed, return original pointer */

	if (ptr == NULL)
	{
		s = malloc(new_size); /* Allocate new memory block */
		if (s == NULL)
			return (NULL); /* Allocation failed */

		return (s); /* Return new memory block */
	}

	if (new_size == 0 && ptr != NULL)
	{
		free(ptr); /* Free memory block */
		return (NULL); /* Return NULL */
	}

	s = malloc(new_size); /* Allocate new memory block */
	if (s == NULL)
		return (NULL); /* Allocation failed */

	aux = ptr;
	for (a = 0; a < old_size; a++)
		s[a] = aux[a]; /* Copy data from old block to new block */

	free(ptr); /* Free old memory block */

	return (s); /* Return new memory block */
}
