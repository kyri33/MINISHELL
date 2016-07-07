#include <stdlib.h>
#include "defs.h"

void	ft_parse_command(char **cmd)
{
	if (ft_strnequ(*cmd, "exit", 4) == TRUE)
		ft_exit(cmd, EXIT_SUCCESS, NULL);
	else if (ft_strnequ(*cmd, "echo", 4) == TRUE)
		ft_echo(cmd);
	else
	{
		ft_putstr(*cmd);
		ft_putendl(": command not found");
	}
}
