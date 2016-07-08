#include <stdlib.h>
#include <unistd.h>
#include "libft.h"
#include "defs.h"

void	ft_cd(char **cmd)
{
	char	**argv;

	argv = NULL;
	if (ft_fill_args(cmd, &argv, "cd") == TRUE)
	{
		if (ft_strlen(argv[1]) == 0)
		{
			ft_error("Usage: cd <path>", NULL);
			return;
		}
		if (access(argv[1], R_OK) < 0)
			ft_error("You do not have access to the directory",
				argv[1]);
		else if (chdir(argv[1]) < 0)
			ft_error("Cannot navigate to directory",
				argv[1]);
	}
	else
		ft_error("There was an unexpected error executing the command\
			.", NULL);
	ft_del_args(&argv);
}
