#include "header.h"

/**
 * @fileExists: check if a file exists
 * Return: true if and only if the file exists, false else
 */
int fileExists(const char *file)
{
	struct stat buf;
	if (stat(file, &buf) == 0)
		return (0);

	else
		return (1);

	return (0);
}
