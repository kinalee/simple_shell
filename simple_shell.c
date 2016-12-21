#include "header.h"

/**
 * main - basic structure function for the simple shell
 * Return: returns 0
 */
int main(void)
{
	char *buffer, *argv[1024];
	size_t size = 1024;

	while (1)
	{
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
		{
			free(buffer);
			exit(1);
		}

		printf("wtf$ ");

		_getline(&buffer, &size);
		_strtok(buffer, argv);
		_exe(argv);
	}
	free(buffer);
	return (0);
}
