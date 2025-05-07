#include <readline/history.h>
#include <readline/readline.h>
#include <stdio.h>
#include <stdlib.h>

int	main(void)
{
	char	*rl;

	rl = readline("minishell > ");
	printf("%s\n", rl);
	free(rl);
	return (0);
}
