#include "header.h"

int main(int ac, char **av)
{
	char *buffer, *argv[1024];
	int i, status;
	int c = 1;
	size_t size = 1024;
	pid_t pid;
	(void)ac;

	while (c != EOF)
	{
		buffer = malloc(sizeof(char) * size);
		if (buffer == NULL)
		{
			free(buffer);
			exit(1);
		}

		printf("$ ");
		c = getline(&buffer, &size, stdin);
		if (c == EOF)
		{
			printf("\n");
			free(buffer);
			exit(0);
		}
		argv[0] = strtok(buffer, " \t\n");
		for (i = 1; argv[i - 1] != NULL; ++i)
		{
			argv[i] = strtok(NULL, " \t\n");
		}
		--i;

		pid = fork();
		if (pid == -1)
		{
			perror("Errors");
			exit(-1);
		}
		if (pid == 0)
		{
			if (execve(argv[0], argv, NULL) == -1)
			{
				perror(av[0]);
			}
			exit(0);
		}

		wait(&status);
	}
	free(buffer);
	return (0);
}
