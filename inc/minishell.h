#ifndef MINISHELL_H
#define MINISHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <readline/readline.h>
#include <readline/history.h>

typedef enum x_type{
	// REDIRECTION,
	// ENVIROMENT,	
	// SINGLE_QUOTE, // '
	// DOUBLE_QUOTE, // "
	INPUT, // <
	OUTPUT, // >
	HERE_DOC, // <<
	APPEND, // >>
	DOLLAR_SIGN, // $
}		t_type;

typedef struct x_red{

	char	*file;
	t_type	type;
	int		check_flag;

}			t_red;

typedef struct x_env{

	char 		*key;
	char 		*value;

}			t_env;

typedef struct x_cmd{
	
	char	*command;
	char	**arguments;
	int		check_red;
	int		check_env;

	t_red 		**s_red;
	t_env 		**s_env;

}		t_cmd;


typedef struct x_bash{

	char	*commands;
	char	**args_pip;
	int		num_cmd;

	t_cmd 	**s_cmd;

}		t_bash;

#endif