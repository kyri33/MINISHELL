#include "defs.h"
#include <fcntl.h>

/* pipefd will be used when writing and reading if any pipes are present in */
/* the command being executed.                                              */
/*                                                                          */
/* stdi_cpy & stdo_cpy are used to keep track of the current STDIN & STDOUT */
/* file descriptors so that once pipefd is no longer needed, we can restore */
/* STDIN & STDOUT to be the original file descriptors which belong to the   */
/* console.                                                                 */

static void	ft_run_pipes(char ***pipes)
{
	int		i;
	int		pipefd[2];
	int		stdi_cpy;
	int		stdo_cpy;

	i = 0;
	stdi_cpy = dup(0);
	stdo_cpy = dup(1);
	if (pipe(pipefd) != 0)
	{
		ft_error("Unable to initialise I/O pipes.", NULL);
		return ;
	}
	while ((*pipes)[i] != NULL)
	{
		if (i == 0 && (*pipes)[i + 1] != NULL)
		{
			dup2(pipefd[1], 1);
			ft_run_command(&((*pipes)[i]));
			dup2(pipefd[0], 0);
		}
		else if (i > 0 && (*pipes)[i + 1] == NULL)
		{
			close(pipefd[1]);
			dup2(stdo_cpy, 1);
			ft_run_command(&((*pipes)[i]));
			dup2(stdi_cpy, 0);
		}
		else
			ft_run_command(&((*pipes)[i]));
		i++;
	}
	close(pipefd[0]);
	close(pipefd[1]);
	close(stdi_cpy);
	close(stdo_cpy);
}

void		ft_exec_pipes(char ***pipes)
{
	int		i;

	i = 0;
	while ((*pipes)[i] != NULL)
	{
		if (ft_rem_spaces(&((*pipes)[i])) == FALSE)
		{
			ft_error("An unexpected error occured while parsing user input.",
				NULL);
			return ;
		}
		i++;
	}
	ft_run_pipes(pipes);
}
