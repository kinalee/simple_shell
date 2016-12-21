#include "header.h"

/**
 * _getline - helper function for getline
 * @buffer: double pointer to the given argument
 * @size: size of the given string
 * Return: returns nothing
 */
void _getline(char **buffer, size_t *size)
{
	ssize_t c;

	c = getline(buffer, size, stdin);
	if (c == EOF)
	{
		printf("\n");
		free(*buffer);
		_exit(0);
	}
}

/**
 * _strtok - helper function for strtok
 * @buffer: the given argument/string
 * @argv: buffer to store tokenized given argument
 * Return: returns nothing
 */
void _strtok(char *buffer, char **argv)
{
	int i;

	argv[0] = strtok(buffer, " \t\n");
	for (i = 1; argv[i - 1] != NULL; ++i)
		argv[i] = strtok(NULL, " \t\n");
}

/**
 * _exe - helper function for forking and executing
 * @argv: double pointer to the given command
 * Return: returns nothing
 */
void _exe(char **argv)
{
	int status;
	char *cmd;
	pid_t pid;

	if (_strcmp(argv[0], "exit") == 0)
		exit(0);

	if (_strcmp(argv[0], "env") == 0)
	    _env();


	pid = fork();
	if (pid < 0)
	{
		printf("\n");
		_exit(-1);
	}
	if (pid == 0)
	{
		cmd = pars_path_dir(argv[0]);
		if (fileExists(cmd) == 0)
		{
			if (execve(cmd, argv, environ) < 0)
			{
				printf("%s: command not found\n", argv[0]);
				_exit(0);
			}
		}
		else
		{
			if (execve(argv[0], argv, environ) < 0)
			{
				printf("%s: command not found\n", argv[0]);
				_exit(0);
			}
		}
	}
	else
		wait(&status);
}

/**
 * _env - prints the current environment
 * Return: returns nothing
 */
void _env(void)
{
        int i;

        for(i = 0; environ[i] != NULL; ++i)
		printf("%s\n", environ[i]);
}
