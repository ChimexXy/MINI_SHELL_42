#include "../../inc/minishell.h"



int	ft_count_word(char *cmd)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (cmd[i])
	{
		while (cmd[i] == '>' || cmd[i] == '<' )
			i++;
		if (cmd[i] !=  )
			j++;
		while (cmd[i] != sep)
			i++;
	}
	return (j);
}

char **tokinzer(char *cmd)
{
	int		word;
	char	**ret;

	if(!cmd)
		return (NULL);
	word = count_word(cmd) + 1;
	ret = malloc(sizeof(char *) * word);
	if (!ret)
		return (NULL);
	ret = alloc_words(ret, cmd, word);
	if (!ret)
		return (NULL);
	return (ret);
}