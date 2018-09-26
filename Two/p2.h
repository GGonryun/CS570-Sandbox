#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include "getword.h"

#define MAX_ARGS 100
#define MAX_FILE 100
#define FALSE 0

int parse();
void prepare(); //a.k.a init.
void redirectoutput();
void redirectinput();
void donothing(int signum);
