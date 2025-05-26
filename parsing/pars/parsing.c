#include "../../inc/minishell.h"

int	select_struct1(t_bash *bash)
{
	char *cmd;

	cmd = readline("minishell$ ");
	if(!cmd || !check_cmd(cmd) || !check_cmd1(cmd))
	{
		bash->num_cmd = 0;
		free(cmd);
		return (0);
	}
	bash->num_cmd = count_pipes(cmd);
	bash->s_cmd = malloc(sizeof(t_cmd *) * (bash->num_cmd + 1));
	if (!bash->s_cmd)
	{
		free(cmd);
		return (0);
	}
	bash->commands = ft_strdup(cmd);
	bash->args_pip = ft_split(cmd, '|');

	return (1);
}

int	select_struct2(t_bash *bash)
{
	int	i;

	i = 0;
	while(i < bash->num_cmd)
	{
		bash->s_cmd[i] = malloc(sizeof(t_cmd));
		if (!bash->s_cmd[i])
			return (0);
		bash->s_cmd[i]->command = ft_strdup(bash->args_pip[i]);
		bash->s_cmd[i]->s_red = NULL;
		bash->s_cmd[i]->s_env = NULL;
		bash->s_cmd[i]->check_env = 0;
		bash->s_cmd[i]->check_red = 0;
		i++;
	}
	bash->s_cmd[i] = NULL;
	return (1);
}

int	main()
{
	t_bash	*bash;

	bash = malloc(sizeof(bash));
	while(1)
	{

	}
}
