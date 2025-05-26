#fndef MINISHELL_H
#define MINISHELL_H

#include <errno.h>
#include <fcntl.h>
#include <readline/history.h>
#include <readline/readline.h>
#include <signal.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sysexits.h>
#include <unistd.h>

typedef struct s_red
{
	char			*file;
	int				type;
	struct red		*next;
}					t_red;

typedef struct s_cmd
{
	char			**args;
	t_red			*redirection;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_env
{
	char			*key;
	char			*value;
	struct s_env	*next;
}					t_env;

typedef struct s_bash
{
	t_env			*envp;
	t_cmd *cmd unsigned char exit_status;
}					t_bash;

/*
 * test cmd ">ksk <ksk >dd ls -la | pwd <<djh <<ggg  |> dfd cat >dsds  <<ll ll"
 */

#endif
