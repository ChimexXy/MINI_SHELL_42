/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quotes.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mozahnou <mozahnou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/02 10:42:47 by mozahnou          #+#    #+#             */
/*   Updated: 2025/07/03 21:47:24 by mozahnou         ###   ########.fr       */
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

static int	ft_handle_escaped_quote(const char *str, char *result,
		t_quote_state *state)
{
	if (str[state->i] == '\\' && str[state->i + 1] &&
		(str[state->i + 1] == '\'' || str[state->i + 1] == '"'))
	{
		result[state->j++] = str[state->i + 1];
		state->i += 2;
		return (1);
	}
	return (0);
}

static void	process_quotes(const char *str, char *result, t_quote_state *state)
{
	if (!state->quote_char && (str[state->i] == '\'' || str[state->i] == '"'))
	{
		state->quote_char = str[state->i];
		state->i++;
	}
	else if (state->quote_char && str[state->i] == state->quote_char)
	{
		state->quote_char = 0;
		state->i++;
	}
	else
	{
		result[state->j++] = str[state->i++];
	}
}

static int	ft_has_quotes(char *s)
{
	while (*s)
	{
		if (*s == '\'' || *s == '"')
			return (1);
		s++;
	}
	return (0);
}

char	*ft_handle_quotes(char *str, int *check_flag)
{
	char			*result;
	t_quote_state	state;

	state.i = 0;
	state.j = 0;
	state.quote_char = 0;
	*check_flag = ft_has_quotes(str);
	if (!str)
		return (NULL);
	result = malloc(ft_strlen(str) + 1);
	if (!result)
		return (NULL);
	while (str[state.i])
	{
		if (ft_handle_escaped_quote(str, result, &state))
			continue ;
		process_quotes(str, result, &state);
	}
	result[state.j] = '\0';
	return (result);
}
