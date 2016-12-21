#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>

extern char **environ;

void _getline(char **buffer, size_t *size);
void _strtok(char *buffer, char **argv);
void _exe(char **argv);
char *_strcat(char *dest, char *src);
int _strcmp(char *s1, char *s2);
char *pars_path_dir(char *argv);
int fileExists(const char *file);
void _env(void);

#endif
