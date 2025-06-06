#ifndef MINISHELL_H
# define MINISHELL_H

// # include "./libft/libft.h"
# include <readline/history.h>
# include <readline/readline.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

# define MAX_PATH_LEN 4096
# define SUCCESS 0
# define ERROR 1

typedef enum x_type
{
	// REDIRECTION,
	// ENVIROMENT,
	// SINGLE_QUOTE, // '
	// DOUBLE_QUOTE, // "
	INPUT,       // <
	OUTPUT,      // >
	HERE_DOC,    // <<
	APPEND,      // >>
	DOLLAR_SIGN, // $
}					t_type;

typedef struct x_red
{
	char			*file;
	t_type			type;
	int				check_flag;

}					t_red;

typedef struct x_env
{
	char			*key;
	char			*value;
	struct x_env	*next;
}					t_env;

typedef struct x_cmd
{
	char			*command;
	char			**arguments;
	int				check_red;
	int				check_env;

	t_red			**s_red;
	t_env			*s_env;
	struct x_cmd	*next;
}					t_cmd;

typedef struct x_bash
{
	char			*commands;
	char			**args_pip;
	int				num_cmd;

	t_cmd			**s_cmd;

}					t_bash;

/*
 * excutions functions
 */
char				*get_env_value(t_env *env_list, char *key);
int					*update_env(t_bash **list_env, t_env *env);
int					*creat_env_node(t_env *env);

//->parsing:

int					select_struct1(t_bash *bash);
int					select_struct2(t_bash *bash);
int					select_struct3(t_bash *bash);
void				select_struct(t_bash *bash);
int					select_struct1(t_bash *bash);
int					select_struct2(t_bash *bash);
int					select_struct3(t_bash *bash);
void				select_struct(t_bash *bash);

//->parsing1:
int					check_cmd(char *str);
int					check_cmd1(char *str);
int					count_pipes(char *cmd);
int					red_parse(t_bash *bash);

//->parsing2:

int					check_redirection(char *str);
int					check_envirment(char *str);
void				check_red_env(t_bash *bash);

//->tokrnizer

char				**tokenizer(char *cmd);
int					check_tokinzer(char c);
int					count_word_tk(char *cmd);
void				free_double_pointer_tk(char **arr, int p);
char				**alloc_words_tk(char **ret, char *cmd, int word);

//->utils(libft)

char				*ft_substr(char *str, int start, int len);
char				**ft_split(char *cmd, char sep);
char				*ft_strdup(char *cmd);
int					ft_strlen(char *cmd);
char				*ft_substr(char *str, int start, int len);

// parsing function
char				**tokenizer(char *cmd);

//->utils(libft)
char				*ft_substr(char *str, int start, int len);
char				**ft_split(char *cmd, char sep);
char				*ft_strdup(char *cmd);
int					ft_strlen(char *cmd);
char				*ft_substr(char *str, int start, int len);

char				*ft_strcmp(char *s1, char *s2);
#endif
