#include <stdlib.h>
#include "defs.h"

void	ft_del_args(char ***argv)
{
	int		i;

	i = 0;
	if (*argv == NULL)
		return;
	while ((*argv)[i] != NULL)
	{
		free((*argv)[i]);
		i++;
	}
	if (*argv != NULL)
		free(*argv);
	*argv = NULL;
}
