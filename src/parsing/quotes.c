/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:42:47 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/02 10:42:47 by mozahnou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minishell.h"

char	ft_check_unclosed_quotes(char *str)
{
	int		i;
	char	quote_char;

	if (!str)
		return (0);
	i = 0;
	quote_char = 0;
	while (str[i])
	{
		if (!quote_char && (str[i] == '\'' || str[i] == '"'))
		{
			quote_char = str[i];
		}
		else if (quote_char && str[i] == quote_char)
		{
			quote_char = 0;
		}
		i++;
	}
	return (quote_char);
}

static int	ft_is_quote(char c)
{
	return (c == '\'' || c == '"');
}

static int	ft_handle_escaped_quote(const char *str, char *result, int *i,
		int *j)
{
	if (str[*i] == '\\' && str[*i + 1] && ft_is_quote(str[*i + 1]))
	{
		result[(*j)++] = str[*i + 1];
		*i += 2;
		return (1);
	}
	return (0);
}

static void	process_quotes(const char *str, char *result, int *i, int *j,
		char *quote_char)
{
	if (!*quote_char && ft_is_quote(str[*i]))
	{
		*quote_char = str[*i];
		(*i)++;
	}
	else if (*quote_char && str[*i] == *quote_char)
	{
		*quote_char = 0;
		(*i)++;
	}
	else
	{
		result[(*j)++] = str[(*i)++];
	}
}

char	*ft_handle_quotes(char *str)
{
	char	*result;
	int		i;
	int		j;
	char	quote_char;

	i = 0;
	j = 0;
	quote_char = 0;
	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (str[i])
	{
		if (ft_handle_escaped_quote(str, result, &i, &j))
			continue ;
		process_quotes(str, result, &i, &j, &quote_char);
	}
	result[j] = '\0';
	return (result);
}
