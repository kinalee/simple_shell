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
