#include "../inc/minishell.h"
#include <csignal>
#include <readline/readline.h>
#include <signal.h>

/*
 * ctr-c function
 */

void	handel_sigint(int sig)
{
	(void)sig;
	rl_on_new_line();
	rl_replace_line("", 0);
	rl_redisplay();
}

/*
 * ctr-/ function
 * this function did nothing
 */

void	handel_sigquit(int sig)
{
	(void)sig;
}

/*
 * ctr-d function
 */

void	handel_sigterm(void)
{
}

void	active_signal(void)
{
	signal(SIGINT, handel_sigint);
	signal(SIGQUIT, handel_sigquit);
}
