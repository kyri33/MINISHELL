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
		if (chdir(argv[1]) < 0)
			ft_error("Cannot navigate to directory",
				argv[1]);
	}
	else
		ft_error("There was an unexpected error executing the command\
			.", NULL);
	ft_del_args(&argv);
}
