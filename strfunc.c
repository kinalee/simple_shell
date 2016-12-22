#include "header.h"
/**
 * _strcat - appends src pointer to the end of dest pointer
 * @dest: destination variable pointer
 * @src: source variable pointer
 * Return: char
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}

	j = 0;
	while (src[j] != '\0')
	{
		dest[i++] = src[j++];
	}
	dest[i] = '\0';
	return (dest);
}

/**
 * _strcmp - campares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: string difference
 */
int _strcmp(char *s1, char *s2)
{
	int i;

	for (i = 0; s1[i] != '\0' || s2[i] != '\0'; i++)
	{
		if (s1[i] == '\0')
			return (1);
		if (s1[i] != s2[i])
			return (-1);
	}
	return (0);
}

/**
 *_strlen - returns the length of the given string
 * @str: given string
 * Return: returns the length of the string
 */
int _strlen(char *str)
{
	int i;

	if (str == NULL)
		return (0);

	for (i = 0; str[i] != '\0'; ++i)
		;

	return (i);
}

/**
 *_strdup - duplicated the given string
 * @str: given string
 * Return: null or address of duplicated string
 */
char *_strdup(char *str)
{
	char *dupstr;
	int i, len;

	len = _strlen(str);
	dupstr = malloc(sizeof(char) * len);

	if (dupstr == NULL)
	{
		free(dupstr);
		return (NULL);
	}

	for (i = 0; str[i] != '\0'; ++i)
		dupstr[i] = str[i];

	return (dupstr);
}
