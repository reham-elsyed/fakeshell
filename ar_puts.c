#include "main.h"
/**
 * ar_puts - puts function
 * @str: input string
 * Return: number of character printed
 */
int ar_puts(const char *str)
{
	int i, count = 0;

	for (i = 0; str[i] != '\0'; i++)
		count += _putchar(str[i]);
	return (count);
}
