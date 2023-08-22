#ifndef _SSH_H_
#define _SSH_H_

#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <errno.h>

/* builtin fucntions declarations */
int builtins(general_t *info, char **arguments);
int check_builtin(general_t *info, char **arguments);

/* exit function declaration */
void bin_exit(general_t *info, char **arguments);
int number_controller(general_t *info, char *number);

/* environment function declaration */
void bin_env(general_t *info, char **arguments);

/* echo call decl. */
void bin_echo(general_t *info, char **arguments);
void echo_printer(int index, char *text, char **arguments);

extern char **environ;

/* command interpreter */
void analyze(char **arguments, general_t *info, char *buff);

/* permissions fucntions */
int is_executable(char *filename);
int is_file(char *command);

/* environment fucntions */
char *_getenv(const char *name);
char *which(char *filename, general_t *info);
void is_current_path(char *path, general_t *info);
void get_full_env(void);

/* execution fucntions */
void execute(char *commands, char **arguments, general_t *info, char *buff);
int current_dir(char *cmd, char **arguments, char *buff, general_t *info);


#endif _SSH_H_  /* close guard */
