#ifndef _SSH_H_
#define _SSH_H_

/* general buitin definitions */
#define _TRUE            1
#define _FALSE           0

#define STDIN            0
#define STDOUT           1
#define STDERR           2

#define NON_INTERACTIVE  0
#define INTERACTIVE      1

#define PERMISSIONS      1
#define NON_PERMISSIONS -1

#define _FILE            10
#define NON_FILE         -10

#define _ENOENT          "No such file or directory"
#define _EACCES          "Permission denied"
#define _CMD_NOT_EXISTS  "not found"
#define _ILLEGAL_NUMBER  "Illegal number"

#define _CODE_ENOENT           3
#define _CODE_EACCES           13
#define _CODE_CMD_NOT_EXISTS   132
#define _CODE_ILLEGAL_NUMBER   133
/* end of general builin definitions */

#include <stdlib.h>
#include <stdio.h>
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

/* general input command data structure */
typedef struct __attribute__((__packed__))
{
	int argc;                 /* Number of arguments received */
	char **argv;              /* Arguments received */
	int mode;                 /* INTERACTIVE or NON_INTERACTIVE */
	int error_code;           /* Error code for error message */
	char *command;            /* Command to execute */
	int n_commands;           /* Number of commands executed */
	char *value_path;         /* Path of a command */
	int is_current_path;      /* Check if is current path or not */
	int status_code;          /* Last exit code */
	char *buffer;             /* Line readed with the getline */
	char **arguments;         /* Line splited into words */
	char *environment;        /* Last environment variable get it */
	int pid;                  /* Process id */
} general_t;

typedef struct __attribute__((__packed__))
{
	char *message;            /* Error message */
	int code;                 /* Error code for identify the error message */
} error_t;

typedef struct __attribute__((__packed__))
{
	char *command;            /* arguments[0] = cmd */
	void (*func)(general_t *info, char **arguments);
} builtin_t;
/* end of data structure definition */


/* error detection fucntions */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);

/* memory allocation fucntions */
void *_realloc(void *ptr, size_t old_size, size_t new_size);
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);

/* main start  point of the simple shell program */
void start(general_t *info);

/* text.c */
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* utils_text.c */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

/* utils_text2.c */
char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* printers_out.c */
int _putchar(char c);
int print(char *msg);

/* printers_err.c */
int print_err(char *msg);

/* tokenization.c */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* patterns.c */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

/* patterns_replacer.c */
char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);

#endif _SSH_H_  /* close guard */
