#include "header.h"

extern char **environ;

char *pars_path_dir(char *argv)
{
	char *dir, *single_dir, *dir_cat, *dup_slash, *dir_dup;

	dir = getenv("PATH");

	single_dir = strtok(dir, ":");
	while (single_dir != NULL)
	{
		dir_dup = strdup(single_dir);
		dup_slash = _strcat (dir_dup, "/");
		dir_cat = _strcat(dup_slash, argv);

		if (fileExists(dir_cat) == 0)
			return(dir_cat);

		single_dir = strtok(NULL, ":");
	}
	return (NULL);
}
