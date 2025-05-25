#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef struct x_cmd{
	
	char	*command;
	char	**arguments;
	int		check_red;
	int		check_env;

}		t_cmd;


typedef struct x_bash{

	char	*commands;
	char	**args;
	int		num_cmd;

	t_cmd **s_cmd;

}		t_bash;

#endif