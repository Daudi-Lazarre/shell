#Stupid Shell!

Description: This repository contains a customized shell that gathers input and executes programs based on that input.

How to Compile: You first need to clone the repository. Make sure to have gcc installed, then run this command to compile gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o ss.
then run with ./ss.

How to use the shell: 
Builtins:

| Command | Description |
| ------ | ------ |
| env | prints all environment variables |
| path | prints all directories in a system path |
| exit | exits the shell |
 
Example 1: ./ss

Example 2: echo "ls -l" | ./ss

Each file's use and functions:
allocate.c: Allocates memory for an array of elements all size bytes long, all at 0. findpath.c: Checks for a valid path. forkExecute.c: Forks and executes command received by user. getenv.c: Retrieves an environmnet variable.  getpath.c: Retrieves paths from environmnet variables. holberton.h: Header file with prototypes. main.c: Shell program entry gets user input and dispatches to proper functions. newPrompt.c: Starts a new prompt. parseInput.c: Breaks up a string into an array of strings. printenv.c: Prints all environment variables. putchar.c: puts.c: runCommand.c strcmp.c: strdup.c: strlen.c:   

Creators: Daudi Lazarre, Peter Thomas, and Patrick Welton

7h15 F1|_3 H4Z b33n h4xx0r3d BY P3T3R th0M4Z 101010101

D4Uc|: H4$ 3N+3R3D 7H3 CH4+
