#include <stdlib.h>
#include "defs.h"

void	ft_exit(char **cmd, int status, char *err)
{
	if (*cmd != NULL)
		free(*cmd);
	if (status == EXIT_FAILURE)
		ft_putendl_fd(err, STDERR);
	exit(status);
}
