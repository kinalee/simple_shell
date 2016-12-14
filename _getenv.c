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
        printf("PATH: %s\n", getenv("PATH"));
	printf("_PATH: %s\n", _getenv("PATH"));
        printf("Whatever: %s\n", getenv("Whatever"));
        printf("_Whatever: %s\n", _getenv("Whatever"));

        return (0);
}
