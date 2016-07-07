#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "libft.h"
#include "defs.h"

static t_bool	ft_fill_args(char **cmd, char ***argv)
{
	char	*arg_start;

	arg_start = NULL;
	if ((*argv = (char **)malloc(sizeof(char*) * 3)) == NULL)
	{
		ft_putendl_fd("There was an unexpected error executing the\
			command.", STDERR);
		return (FALSE);
	}
	(*argv)[0] = ft_strdup("echo");
	if ((arg_start = ft_strchr(*cmd, ' ')) == NULL)
		(*argv)[1] = ft_strdup("");
	else
		(*argv)[1] = ft_strdup(arg_start + 1);
	(*argv)[2] = NULL;
	if ((*argv)[0] == NULL || (*argv)[1] == NULL)
		return (FALSE);
	return (TRUE);
}

static void	ft_del_args(char ***argv)
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
	if (argv != NULL)
		free(*argv);
}

void	ft_echo(char **cmd)
{
	char	**argv;
	pid_t	pid;

	argv = NULL;
	pid = -1;
	if (ft_fill_args(cmd, &argv) == TRUE)
	{
		if ((pid = fork()) >= 0)
		{
			if (pid == 0)
			{
				execv("/bin/echo", argv);
			}
			else
				waitpid(pid, 0, 0);
		}
	}
	ft_del_args(&argv);
	return;
}
