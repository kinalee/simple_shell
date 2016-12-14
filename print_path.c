#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

extern char **environ;

char *_getenv(const char *name)
{
        int i;
        char *env;

        for (i = 0; environ[i] != NULL; ++i)
        {
                env = strtok(environ[i], "=");
		if (strcmp(env, name) == 0)
		{
			env = strtok(NULL, "=");
			return(env);
		}
        }

        return(NULL);
}

int main(void)
{
	char *path, *tok;
	int i;

	path = _getenv("PATH");
	tok = strtok(path, ":");

	for (i = 0; tok != '\0'; ++i)
	{
		printf("%s\n", tok);
		tok = strtok(NULL, ":");

	}
        return (0);
}
