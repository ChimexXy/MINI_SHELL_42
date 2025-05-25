#include "../../inc/minishell.h"



int	select_struct1(t_bash *bash)
{
	int	i;
	char *cmd;

	i = 0;
	cmd = readline("minishell$ ");
	if(!cmd)
	{
		free(cmd);
		return (0);
	}

	return (1);
}

void	select_struct2(t_bash *bash, char *read_line)
{

}

int	main()
{
	t_bash	*bash;

	bash = malloc(sizeof(bash));
	while(1)
	{

	}
}
