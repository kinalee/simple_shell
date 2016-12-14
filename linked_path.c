#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

typedef struct node
{
        char *path;
        struct node *next;
} p_list;

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
	char *get_path, *tok;
	int i;
	p_list *head, *node;

	get_path = _getenv("PATH");
	tok = strtok(get_path, ":");

	head = NULL;

	for (i = 0; tok != '\0'; ++i)
	{
		node = malloc(sizeof(p_list));
		if (node == NULL)
		{
			free(node);
			return (1);
		}

		node->path = tok;
		node->next = head;
		head = node;
		printf("%s\n", node->path);
		tok = strtok(NULL, ":");
	}
        return (0);
}
