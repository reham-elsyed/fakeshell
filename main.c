#include "main.h"
/**
 * main - simple shell app
 * @ac: args count
 * @av: args list
 * Return: 0
 */
int main(int ac, char **av)
{
	char *promp = "ar$ ", *delim = " ", *token;
	char *line, *line_cpy;
	size_t line_len = 0, i, j;
	int state;

	while (1)
	{
		ac = 1;
		ar_puts(promp);
		state = ar_getline(&line, &line_len, stdin);
		if (state == -1)
			ar_exerror();
		line_cpy = malloc(sizeof(char) * line_len + 1);
		if (line_cpy == NULL)
			ar_exerror();
		ar_strcpy(line_cpy, line);
		token = ar_strtok(line, delim);
		while (token != NULL)
		{
			ac++;
			token = ar_strtok(NULL, delim);
		}
		av = malloc(sizeof(char *) * ac);
		if (av == NULL)
			ar_exerror();
		token = ar_strtok(line_cpy, delim);
		for (i = 0; token != NULL; i++)
		{
			av[i] = token;
			for (j = 0; av[i][j] != '\n' && av[i][j] != '\0'; j++)
				;
			av[i][j] = '\0';
			token = ar_strtok(NULL, delim);
		}
		av[i] = NULL;
		printf("send token from main to ar_execute: %s\n", token);
		ar_execute(av);
	}
	for (i = 0; i < (size_t) ac; i++)
		free(av[i]);
	free(av);
	free(token);
	free(line);
	free(line_cpy);
	return (0);
}
