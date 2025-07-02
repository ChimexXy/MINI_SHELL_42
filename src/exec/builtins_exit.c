/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:41:29 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/02 10:41:29 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

static char	*ft_skip_leading_whitespace(char *str)
{
	char	*start;

	if (!str)
		return (NULL);
	start = str;
	while (*start && (*start == ' ' || *start == '\t' || *start == '\n'
			|| *start == '\r' || *start == '\f' || *start == '\v'))
		start++;
	return (start);
}

static char	*ft_strtrim_whitespace(char *str)
{
	char	*start;
	char	*end;
	char	*result;
	int		len;
	int		i;

	start = ft_skip_leading_whitespace(str);
	if (!start || !*start)
		return (ft_strdup(""));
	end = start + ft_strlen(start) - 1;
	while (end > start && (*end == ' ' || *end == '\t' || *end == '\n'
			|| *end == '\r' || *end == '\f' || *end == '\v'))
		end--;
	len = end - start + 1;
	result = malloc(len + 1);
	if (!result)
		return (NULL);
	i = 0;
	while (i < len)
	{
		result[i] = start[i];
		i++;
	}
	result[len] = '\0';
	return (result);
}

static int	ft_parse_sign_and_digits(char *str, int *sign, int *start_pos)
{
	*sign = 1;
	*start_pos = 0;
	if (str[0] == '-')
	{
		*sign = -1;
		*start_pos = 1;
	}
	else if (str[0] == '+')
	{
		*start_pos = 1;
	}
	if (!str[*start_pos])
		return (0);
	return (1);
}

int	ft_atol_safe(char *str, long *result)
{
	long	num;
	int		sign;
	int		i;
	long	prev;

	if (!str || !*str)
		return (0);
	if (!ft_parse_sign_and_digits(str, &sign, &i))
		return (0);
	num = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		prev = num;
		num = num * 10 + (str[i] - '0');
		if (num < prev)
			return (0);
		if (sign == 1 && num > LONG_MAX)
			return (0);
		if (sign == -1 && num > LONG_MAX)
			return (0);
		i++;
	}
	*result = num * sign;
	return (1);
}

static int	ft_is_valid_exit_arg(char *str)
{
	char	*trimmed;
	long	result;
	int		valid;

	if (!str)
		return (0);
	trimmed = ft_strtrim_whitespace(str);
	if (!trimmed || !*trimmed)
	{
		free(trimmed);
		return (0);
	}
	valid = ft_atol_safe(trimmed, &result);
	free(trimmed);
	return (valid);
}

static long	ft_get_exit_value(char *str)
{
	char	*trimmed;
	long	result;

	trimmed = ft_strtrim_whitespace(str);
	ft_atol_safe(trimmed, &result);
	free(trimmed);
	return (result);
}

int	ft_builtin_exit(t_shell *shell, char **args)
{
	long	exit_code;

	ft_putstr_fd("exit\n", 2);
	if (args[1])
	{
		if (!ft_is_valid_exit_arg(args[1]))
		{
			ft_print_exit_error(args[1], NUMERIC_REQUIRED);
			ft_cleanup_shell(shell);
			rl_clear_history();
			exit(2);
		}
		if (args[2])
		{
			ft_print_exit_error(NULL, TOO_MANY_ARGS);
			return (1);
		}
		exit_code = ft_get_exit_value(args[1]);
	}
	else
		exit_code = shell->exit_status;
	ft_cleanup_shell(shell);
	rl_clear_history();
	exit((unsigned char)exit_code);
}
