#include "main.h"
/**
 * ar_getline - getline func
 * @lineptr: input line pointer
 * @n: input pointer of size
 * @stream: input stream
 * Return: number of character readed
 */
ssize_t ar_getline(char **lineptr, size_t *n, FILE *stream)
{
	return (getline(lineptr, n, stream));
}
