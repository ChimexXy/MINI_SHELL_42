#include "../../include/minishell.h"

int check_cmd(char *cmd)
{
	if (!ft_handle_qoutes(cmd))
		return (0);
	else if (!ft_handle_pipe1(cmd))
		return (0);
	else if (!ft_handle_pipe2(cmd))
		return (0);
	else if (!ft_handle_pipe3(cmd))
		return (0);
	else if (!ft_handle_redirectin1(cmd))
		return (0);
	else if (!ft_handle_redirectin2(cmd))
		return (0);
	return (1);
}

int ft_handle_qoutes(char *cmd)
{
	int		i;
	char	c;
	int		state;

	i = 0;
	state = 0;
	if (!cmd)
		return (0);
	while (cmd[i])
	{
		if (cmd[i] == 34 || cmd[i] == 39)
		{
			c = cmd[i];
			i++;
			while (cmd[i] && cmd[i] != c)
				i++;
			if (!cmd[i])
			{
				printf("qoutes error \n");
				return (0);
			}
		}
		i++;
	}
	return (1);
}

int	ft_handle_pipe1(char *cmd)
{
	int	i;

	i = 0;
	while ((cmd[i] >= 9 && cmd[i] <= 13) || cmd[i] == 32)
		i++;
	if (cmd[i] == '|')
	{
		if (cmd[i + 1] == '|')
			printf("bash: syntax error near unexpected token `||'\n");
		else
			printf("bash: syntax error near unexpected token `|'\n");
		return (0);
	}
	while (cmd[i])
	{
		if (cmd[i] == '|' && cmd[i + 1] == '|')
		{
			printf("invalid token :( \n");
			return (0);
		}
		i++;
	}
	return (1);
}

int	ft_handle_pipe2(char *check_cmd1)
{
	int	i;

	i = ft_strlen(check_cmd1) - 1;
	while (i >= 0 && check_cmd1[i] == ' ')
		i--;
	if (check_cmd1[i] == '|')
	{
		printf("invalid token :(\n");
		return (0);
	}
	return (1);
}

int	ft_handle_pipe3(char *cmd)
{
	int	i;

	i = 0;
	while (cmd[i])
	{
		if (cmd[i] == '|')
		{
			i++;
			if (!cmd[i])
				return (0);
			while(cmd[i] == ' ')
				i++;
			if(cmd[i] == '|' || cmd[i] == '\0')
			{
				printf("bash: syntax error near unexpected token `|'\n");
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

int	ft_handle_redirectin1(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while(str[i])
	{
		x = 0;
		if (str[i] == '>')
		{
			while(str[i] && str[i] == '>')
			{
				i++;
				x++;
			}
			if (x > 2 || str[i] == '<')
			{
				printf("unexpected token '>>' \n");	
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}

int	ft_handle_redirectin2(char *str)
{
	int	i;
	int	x;

	i = 0;
	x = 0;
	while(str[i])
	{
		x = 0;
		if (str[i] == '<')
		{
			while (str[i] && str[i] == '<')
			{
				i++;
				x++;
			}
			if (x > 2 || (x == 2 && str[i] == '>'))
			{
				printf("unexpected token '<<' \n");	
				return (0);
			}
		}
		else
			i++;
	}
	return (1);
}
