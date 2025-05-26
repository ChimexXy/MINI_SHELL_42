#include "../../inc/minishell.h"

int red_parse(t_bash *bash)
{
	int i;
	int j;

	i = 0;
	while (i < bash->num_cmd)
	{
		j = ft_strlen(bash->s_cmd[i]->command) - 1;
		while (j >= 0 && (bash->s_cmd[i]->command[j] == ' ' 
			|| bash->s_cmd[i]->command[j] == '\t'))
			j--;
		if (j >= 0 && (bash->s_cmd[i]->command[j] == '>' 
			|| bash->s_cmd[i]->command[j] == '<'))
			return (0);
		i++;
	}
	return (1);
}
