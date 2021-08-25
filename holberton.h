#ifndef _HOLBERTON_H
#define _HOLBERTON_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

void new_prompt(void);
int getProcessID(void);
void print_env(char **env);
int _putchar(char c);
void _puts(char *str);
int _strcmp(char *s1, char *s2);
void *_allocate(size_t num, size_t size);
char **parse_input(char *input);
#endif
