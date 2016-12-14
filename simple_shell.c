#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char *buffer;
	size_t size = 100;
	int c = 1;

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

		printf("%s", buffer);
	}

	return (0);
}
