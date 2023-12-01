#include "main.h"
/**
 * ar_exerror - program error and exit
 */
void ar_exerror()
{
	ar_perror("error: something has happened");
	exit(-1);
}
