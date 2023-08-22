#include "ssh.h"

/**
 * is_executable - Check if a filename has execute permissions
 * and is a regular file.
 *
 * @filename: Filename to check.
 *
 * Return: On success, PERMISSIONS (1) if executable,
 * NON_PERMISSIONS (0) if not executable.
 *         On error or if the file doesn't exist, NON_FILE (-1).
 *
 * This function checks if the specified @filename is executable
 * and a regular file.
 * If the file is executable, it returns PERMISSIONS (1).
 * If the file is not executable or doesn't exist,
 * it returns NON_PERMISSIONS (0).
 * If there's an error or the file doesn't exist, it returns NON_FILE (-1).
 **/
int is_executable(char *filename)
{
    struct stat stats;

    if (stat(filename, &stats) == 0)
    {
        if (stats.st_mode & X_OK)
            return (PERMISSIONS); /* File is executable */
        else
            return (NON_PERMISSIONS); /* File is not executable */
    }

    return (NON_FILE); /* File doesn't exist or error occurred */
}

/**
 * is_file - Check if a path is a regular file with execute permissions.
 *
 * @path: Path to check.
 *
 * Return: If the path points to a regular file with execute permissions,
 * PERMISSIONS (1).
 *         If the path points to a file without execute permissions
 *         or doesn't exist, NON_PERMISSIONS (0).
 *         If the path is not a file, NON_FILE (-1).
 *
 * This function checks if the specified @path is a regular file
 * and if it has execute permissions.
 * If the path points to a regular file with execute permissions,
 * it returns PERMISSIONS (1).
 * If the path points to a file without execute permissions or doesn't exist,
 * it returns NON_PERMISSIONS (0).
 * If the path is not a file, it returns NON_FILE (-1).
 **/
int is_file(char *path)
{
    int i, size;

    size = _strlen(path);
    for (i = 0; i < size; i++)
    {
        if (path[i] == '/')
            return (is_executable(path)); /* Check if the path is executable*/
    }

    return (NON_FILE); /* Path is not a regular file */
}
