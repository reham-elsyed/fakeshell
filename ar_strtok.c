#include "main.h"
/**
 * ar_strtok - make tokens from string
 * @str: input string
 * @delim: input delim
 * Return: current token
 */
char *ar_strtok(char *str, const char *delim)
{
	return (strtok(str, delim));
}
