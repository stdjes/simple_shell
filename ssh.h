#ifndef _SSH_H_
#define _SSH_H_

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



#endif _SSH_H_  /* close guard */
