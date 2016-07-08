#include <stdlib.h>
#include "libft.h"
#include "defs.h"

t_bool	ft_fill_args(char **cmd, char ***argv, char *exec_name)
{
	char	*arg_start;

	if ((*argv = (char **)malloc(sizeof(char *) * 3)) == NULL)
		return (FALSE);
	(*argv)[0] = ft_strdup(exec_name);
	if ((arg_start = ft_strchr(*cmd, ' ')) == NULL)
		(*argv)[1] = ft_strdup("");
	else
		(*argv)[1] = ft_strdup(arg_start + 1);
	(*argv)[2] = NULL;
	if ((*argv)[0] == NULL || (*argv)[1] == NULL)
		return (FALSE);
	return (TRUE);
}
