#include <stdlib.h>
#include "libft.h"
#include "defs.h"

static char	*ft_get_val(char *eq)
{
	int		i;
	int		size;
	char	*val;

	i = 0;
	size = 0;
	val = NULL;
	eq++;
	while (eq[size] != '\0' && eq[size] != ' ' && eq[size] != '\t')
		size++;
	if (size == 0)
		return (NULL);
	if ((val = ft_strnew(size)) != NULL)
	{
		while (i < size)
		{
			val[i] = eq[i];
			i++;
		}
		val[i] = '\0';
	}
	return (val);
}

static char	*ft_get_name(char *eq)
{
	int		i;
	int		size;
	char	*name;

	i = 0;
	size = 0;
	name = NULL;
	while (*eq != ' ' && *eq != '\t')
		eq--;
	eq++;
	while (eq[size] != '=')
		size++;
	if (size == 0)
		return (NULL);
	if ((name = ft_strnew(size)) != NULL)
	{
		while (i < size)
		{
			name[i] = eq[i];
			i++;
		}
		name[i] = '\0';
	}
	return (name);
}

void		ft_setenv(char **cmd)
{
	int		i;
	char	*eq;

	i = 0;
	eq = NULL;
	if (ft_strnequ(*cmd, "setenv ", 7) == FALSE)
	{
		ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
		return;
	}
	eq = ft_strchr(*cmd, '=');
	while(eq != NULL)
	{
		if (ft_get_name(eq) == NULL || ft_get_val(eq) == NULL)
			ft_error("Usage: setenv [NAME]=[VALUE]", NULL);
		else if (setenv(ft_get_name(eq), ft_get_val(eq), TRUE) ==
				FAILURE)
			ft_error("Unable to set environment variable",
				ft_get_name(eq));
		eq = ft_strchr(eq + 1, '=');
	}
}
