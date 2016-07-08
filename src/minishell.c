#include <stdlib.h>
#include "defs.h"

static t_bool	ft_isspace(char c)
{
	return (c == ' ' || c == '\t');
}

static t_bool	ft_rem_spaces(char **cmd)
{
	int		i;
	char	*ret;

	i = 0;
	ret = NULL;
	while ((*cmd)[i] != '\0' && ft_isspace((*cmd)[i]) == TRUE)
		i++;
	if ((*cmd)[i] == '\0')
		return (TRUE);
	if ((ret = ft_strdup(*cmd + i)) == NULL)
		return (FALSE);
	free(*cmd);
	*cmd = NULL;
	*cmd = ret;
	return (TRUE);
}

int		main(void)
{
	char		*cmd;

	cmd = NULL;
	while (1)
	{
		if (cmd != NULL)
		{
			free(cmd);
			cmd = NULL;
		}
		ft_putstr(ft_get_user());
		ft_putstr("@minishell$ ");
		if (get_next_line(STDIN, &cmd) == FAILURE)
			ft_error("An unexpected error occured while\
				reading user input.", NULL);
		if (ft_rem_spaces(&cmd) == FALSE)
			ft_error("An unexpected error occured while\
				reading user input.", NULL);
		ft_parse_command(&cmd);
	}
	ft_exit(&cmd, EXIT_SUCCESS, NULL);
	return (0);
}
