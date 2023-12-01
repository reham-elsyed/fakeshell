#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <errno.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>
#define LINESIZE 1024
extern char **environ;
int ar_puts(const char *);
int _putchar(char);
char *ar_strcpy(char *, const char *);
ssize_t ar_getline(char **, size_t *, FILE *);
char *ar_strtok(char *, const char *);
void ar_perror(const char *);
void ar_exerror(void);
int ar_strcmp(const char *, const char *);
void ar_execute(char **);
char *ar_strcat(char *, const char *);
size_t ar_strlen(const char *str);
int ar_execve(const char *, char *const[], char *const[]);
char *locate(const char *filename);
char *_getenv(const char *name);
char *join_path(const char sep,const char *path1, const char *path2);
char *_strdup(const char *str);
void mask(void);
char *readprompt(void);
char **parseline(char *line);
#endif
