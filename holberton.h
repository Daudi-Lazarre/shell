#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/wait.h>

void rev_string(char *s);
char *itoa(int num, char *str, int base);
void new_prompt(void);
void print_env(char **env);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
void *_allocate(size_t num, size_t size);
char **parse_input(char *input, size_t *size);
char *_getenv(char *variable, char **env);
char **_getpath(char **env);
char *_strdup(char *str);
int _strlen(char *s);
int execute(char *cmd, char **command, char **env, char **av);
char *findpath(char *command, char **path);
int run_command(char **command, char **path, char **env, char **av);
#endif
