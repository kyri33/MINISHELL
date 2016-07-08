#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static t_bool	ft_set_var(char *name, char *val, char ***env, int i)
{
	char	*tmp;
	char	*tmp2;

	tmp = NULL;
	if ((tmp = ft_strjoin(name, "=")) == NULL)
		return (FALSE);
	if ((tmp2 = ft_strjoin(tmp, val)) == NULL)
	{
		free(tmp);
		return (FALSE);
	}
	free((*env)[i]);
	free(tmp);
	(*env)[i] = tmp2;
	return (TRUE);
}

static t_bool	ft_dup_env(char ***environ, char ***tmp)
{
	int		size;
	int		i;

	size = 1;
	i = 0;
	while ((*environ)[size] != NULL)
		size++;
	if ((*tmp = (char **)malloc(sizeof(char *) * (size + 1))) == NULL)
		return (FALSE);
	while (i < size)
	{
		if (((*tmp)[i] = ft_strdup((*environ)[i])) == NULL)
			return (FALSE);
		i++;
	}
	(*tmp)[i] = NULL;
	(*tmp)[i + 1] = NULL;
	return (TRUE);	
}

static t_bool	ft_add_var(char *name, char *val, char ***env)
{
	int		i;
	char **tmp;

	i = 0;
	tmp = NULL;
	if (ft_dup_env(env, &tmp) == FALSE)
		return (FALSE);
	while (tmp[i] != NULL)
		i++;
	if (ft_set_var(name, val, &tmp, i) == FALSE)
		return (FALSE);
	*env = tmp;
	return (TRUE);
}

static t_bool	ft_set(char *name, char *val)
{
	extern char	**environ;
	char		*eq;
	int			i;

	i = 0;
	eq = NULL;
	while (environ[i] != NULL)
	{
		eq = ft_strchr(environ[i], '=');
		if (ft_strequ(ft_get_env_name(environ[i]), name) == TRUE)
		{
			if (ft_set_var(name, val, &environ, i) == FALSE)
				return (FALSE);
			else
				return (TRUE);
		}
		i++;
	}
	return (ft_add_var(name, val, &environ));
}

void		ft_setenv(char **cmd)
{
	int		i;
	char	*eq;

	i = 0;
	eq = ft_strchr(*cmd, '=');
	if (ft_strnequ(*cmd, "setenv ", 7) == FALSE || eq == NULL)
	{
		ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
		return;
	}
	while(eq != NULL)
	{
		i = 0;
		while (*(eq - i) != ' ' && *(eq - i) != '\t')
			i++;
		if (ft_get_env_name(eq - i + 1) == NULL || ft_get_env_val(eq)
				== NULL)
			ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
		else if (ft_set(ft_get_env_name(eq - i + 1), ft_get_env_val(eq
				)) == FALSE)
			ft_error("Unable to set environment variable",
				ft_get_env_name(eq - i + 1));
		eq = ft_strchr(eq + 1, '=');
	}
}
