#include "getword.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <errno.h>

#define MAX_ARGS 100
#define MAX_FILE 100
#define FALSE 0

int parse();
void outputmacro();
void inputmacro();
void pipemacro();
void executemacro();
void dupmacro(int newfd, int oldfd);
void closemacro(int fd);
int ismeta(char* s);
void donothing();
