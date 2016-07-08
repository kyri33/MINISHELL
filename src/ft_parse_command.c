#include <stdlib.h>
#include "defs.h"

void	ft_parse_command(char **cmd)
{
	if (ft_strnequ(*cmd, "exit", 5) == TRUE ||
			ft_strnequ(*cmd, "exit ", 5))
		ft_exit(cmd, EXIT_SUCCESS, NULL);
	else if (ft_strnequ(*cmd, "echo", 4) == TRUE ||
			ft_strnequ(*cmd, "echo ", 5))
		ft_echo(cmd);
	else if (ft_strnequ(*cmd, "cd", 3) == TRUE ||
			ft_strnequ(*cmd, "cd ", 3) == TRUE)
		ft_cd(cmd);
	else if (ft_strnequ(*cmd, "setenv", 6) == TRUE)
		ft_setenv(cmd);
	else
		ft_error(*cmd, "command not found");
}
