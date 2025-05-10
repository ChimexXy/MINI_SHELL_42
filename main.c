#include "minishell.h"

int	main(void)
{
	char	*input;

	input = readline("minishell > ");
	printf("%s", input);
	return (0);
}
