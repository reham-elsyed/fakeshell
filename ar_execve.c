#include "main.h"
/**
 * ar_execve - execve
 * @pathname: pathname
 * @argv: argmunets
 * @envp: environ
 * Return: failed
 */
int ar_execve(const char *pathname, char *const argv[], char *const envp[])
{
	pid_t pid;
	int status = 0;

	pid = fork();
	if (pid == 0)
	{
		if (execve(pathname, argv, envp) == -1)
			ar_perror("error");
		exit(-1);
	}
	else if (pid > 0)
	{
		waitpid(pid, &status, 0);
		if (status) return (-1);
		else return (1);
	}
	else
	{
		return (-1);
	}
	return (-1);
}

