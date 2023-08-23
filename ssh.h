#ifndef SSH_H
#define SSH_H

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


/* error detection fucntions */
char *message_selector(general_t info);
void error(general_t *info);
void error_extra(general_t *info, char *extra);

/* memory allocation fucntions */
void _realloc(void *ptr, size_t old_size, size_t new_size);
void free_memory_p(void *ptr);
void free_memory_pp(void **ptr);

/* main start  point of the simple shell program */
void start(general_t *info);

/* imput prompt and signal handlers */
void start_prompt(general_t *info);
void prompt(general_t *info);
char *read_prompt();
void sigintHandler(int sig_num);

/* input string manipulation fucntions */
int _strlen(char *msg);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);
char *_strdup(char *str);
int _strcmp(char *str1, char *str2);

char *to_string(int number);
int is_numerical(unsigned int n);
int _atoi(char *s);
int contains_letter(char *s);

/* printers.c */
int _putchar_to_fd(char l, int fd);
int print_to_fd(char *msg, int fd);

/* command line output printers */
int _putchar(char c);
int print(char *msg);

/* error printer function */
int print_err(char *msg);

/* input promp join/split */
char **split_words(char *line, const char *sep);
char *join_words(char *word1, char *word2, char *word3, const char *sep);

/* patterns handlers */
void analyze_patterns(general_t *info, char **arguments);
char *pattern_handler(general_t *info, char *string);
char *replace_value(general_t *info, int *index, char *string);

char *replacement(general_t *info, int *index, char *string);
char *replace_env(general_t *info, char *environment);

#endif /* _SSH_H_ */
