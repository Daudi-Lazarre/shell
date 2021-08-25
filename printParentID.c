#include "holberton.h"

/**
 * main - PID
 *
 * Return: Always 0.
 */
int getProcessID(void)
{
    pid_t childPid;

    childPid = getpid();
    printf("%u\n", childPid);
    return (0);
}
