#include "main.h"
/**
 * locate -function to getenv and locate path for executable
 * @filename: name of input token
 * Return:path
 */

char *locate(const char *filename) {
char *path, *dir_path, *file_path, *token;

path = _getenv("PATH");
printf("gotpath: %s\n", path);

dir_path = NULL;
file_path = NULL;

if (path == NULL)
return NULL;

if (file_exist(filename)) {
printf("filename exists in locate first if statement\n");
return _strdup(filename);
}

token = strtok(_strdup(path), ":");
while (token != NULL) {
dir_path = token;
file_path = join_path('/', dir_path, filename);

if (file_exist(file_path))
{
break;
}

token = strtok(NULL, ":");
}

free(path);

return (file_path);
}

char *_getenv(const char *name) {
size_t i = 0, k;
const char *env = NULL;

while (environ[i] != NULL) {
env = environ[i];
k = 0;

while (env[k] == name[k] && env[k] != '=' && env[k] != '\0' && name[k] != '\0')
k++;
if (name[k] == '\0')
{
printf("_getenv works\n");
return (_strdup(env));
}

i++;
}
return NULL;
}
char *_strdup(const char *str) {
    size_t i = 0;
    size_t len = 0;
    char *_str = NULL;

    while (str[i++])
        ;
    len += i;
    _str = malloc(sizeof(*_str) * (len + 1));
    i = 0;
    while (i <= len) {
        _str[i] = str[i];
        i++;
    }
    printf("strdup worked %s\n", _str);
    return _str;
}

int file_exist(const char *path) {
    struct stat buffer;
    if (stat(path, &buffer) == 0)
        return 1;
    printf("file exist worked\n");
    return 0;
}

char *join_path(const char sep, const char *path1, const char *path2) {
    size_t len = strlen(path1) + strlen(path2) + 2;
    char *joined = malloc(sizeof(*joined) * len);

    if (joined == NULL) {
        perror("malloc joined failed\n");
        exit(EXIT_FAILURE);
    }

    strcpy(joined, path1);
    joined[strlen(path1)] = sep;
    strcpy(joined + strlen(path1) + 1, path2);

    printf("joined worked %s\n", joined);
    return joined;
}
/**
 * ar_execop - execute operation
 * @op: input operation
 * @av: input argv
 * @env: input environment
 * Return: state
 */
char *ar_execop(const char *op, char *const av[], char *const env[])
{
	int i;
	char *exit_op = "exit";
	char *env_op = "env";
printf("ar_execop ");
	if (ar_strcmp(exit_op, op) == 0)
		exit(2);
	if (ar_strcmp(env_op, op) == 0)
	{
		for (i = 0; env[i] != NULL; i++)
			ar_puts(env[i]), _putchar('\n');
		return (NULL);
	}
	printf("moving to locate function%s\n", op);
	return (locate(op));
}
/**
 * is_path - check if path
 * @str: input
 * Return: zero or one
 */
int is_path(char *str)
{
	int i;

	for (i = 0; str[i] != '\0'; i++)
		if (str[i] == '/')
			return (1);
	return (0);
}

/**
 * ar_execute - execute operation using argv
 * @av: input argv
 */
void ar_execute(char **av)
{

	extern char **environ;

	
	if (is_path(av[0]))
	{printf("ar_execute if is pathcheck no\n");
		fflush(stdout);
		if (ar_execve(av[0], av, environ) == -1)
			ar_perror("error");
	}
	else
	{printf("ar_execute if is pathcheck yes\n");
		fflush(stdout);
		ar_execop(av[0], av, environ);
	}
}
