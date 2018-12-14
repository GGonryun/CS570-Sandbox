/* ====== BRINGING IN DEPENDENCES ====== */
#include "getword.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <strings.h>
#include <unistd.h>
#include <fcntl.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <libgen.h>
/* ====== DEFINES FOR READIBILITY ====== */
#define ARGUMENTS 100
#define TERMINATE -255
#define MAX_PIPES 10
#define S_PUSH ">"
#define S_PULL "<"
#define S_HERE "<<"
#define S_PIPE "|"
#define S_WAIT "&"
#define S_TILDE "~"
#define SUCCESS 0
#define FAILURE -1
#define FLAG_LIMIT 1
#define FALSE 0
#define TRUE 1
#define HEREIS_FILE ".hereis"
#define DIRECTORY "/etc/passwd"
/* ======= FUNCTION DECLARATIONS ======= */
int parse();
char* finduser(char* who);
void hereismacro();
void outputmacro();
void inputmacro();
int pipemacro();
void executemacro();
void dupmacro(int newfd, int oldfd);
void closemacro(int fd);
int ismeta(char* s);
void donothing();



