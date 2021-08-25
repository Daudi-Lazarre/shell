#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

/**
 * struct dir_t - Struct to store path directories
 * @dir: directory path.
 * @next: A pointer to next list, or null
 */
typedef struct dir_t
{
	char *dir;
	struct dir_t *next;
} dir_s;

void new_prompt(void);
int getProcessID(void);
void print_env(char **env);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
void *_allocate(size_t num, size_t size);
char **parse_input(char *input);
char *_getenv(char *variable, char **env);
char **_getpath(char **env);
char *_strdup(char *str);
int _strlen(char *s);
#endif
