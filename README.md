# Stupid Shell!

Description: This repository contains a customized shell that gathers input and executes programs based on that input.

How to Compile: You first need to clone the repository. Make sure to have gcc installed, then run this command to compile:
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o ss.
then run with ./ss.

## How to Use the Shell
![flowchart](https://user-images.githubusercontent.com/77690147/131719095-e2efc422-70bb-4824-81e9-7238f2866c16.jpg) ![flowchart-Steps](https://user-images.githubusercontent.com/77690147/131720545-c26ba281-1e26-460e-b6f6-e169f3193d16.jpg)
![cl4p-tp](https://user-images.githubusercontent.com/77690147/131721445-ebf9d4e3-a47d-4fcc-b1f5-5cf4054f26ef.jpg) ![bmo-2](https://user-images.githubusercontent.com/77690147/131721457-2fbf8879-9291-4b6a-9833-63cecd75263e.jpg)

Builtins:

| Command | Description |
| ------ | ------ |
| env | prints all environment variables |
| path | prints all directories in a system path |
| exit | exits the shell |
 
Example 1: ./ss

Example 2: echo "ls -l" | ./ss

## Each File's Use and Functions
allocate.c: Allocates memory for an array of elements all size bytes long, all at 0. findpath.c: Checks for a valid path. forkExecute.c: Forks and executes command received by user. getenv.c: Retrieves an environmnet variable.  getpath.c: Retrieves paths from environmnet variables. holberton.h: Header file with prototypes. main.c: Shell program entry gets user input and dispatches to proper functions. newPrompt.c: Starts a new prompt. parseInput.c: Breaks up a string into an array of strings. printenv.c: Prints all environment variables. putchar.c: writes the character c to stdout. puts.c: Writes an array of chars, no newline. runCommand.c: Runs the supplied command. strcmp.c: Compares two strings.  strdup.c: Return pointer to copy of string given as param. strlen.c: Calculates length of string.    

Creators: Daudi Lazarre, Peter Thomas, and Patrick Welton

7h15 F1|_3 H4Z b33n h4xx0r3d BY P3T3R th0M4Z 101010101

D4Uc|: H4$ 3N+3R3D 7H3 CH4+
