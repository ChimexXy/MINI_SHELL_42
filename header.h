
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
	t_cmd			*cmd;
	unsigned char	exit_status;
}

/*
 * test cmd ">ksk <ksk >dd ls -la | pwd <<djh <<ggg  |> dfd cat >dsds  <<ll ll"
 */
