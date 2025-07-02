#include "../../include/minishell.h"

void	ft_print_exit_error(char *arg, char *message)
{
	write(STDERR_FILENO, "minishell: exit: ", 17);
	if (arg)
	{
		write(STDERR_FILENO, arg, ft_strlen(arg));
		write(STDERR_FILENO, ": ", 2);
	}
	if (message)
		write(STDERR_FILENO, message, ft_strlen(message));
	write(STDERR_FILENO, "\n", 1);
}