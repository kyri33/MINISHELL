#include <stdlib.h>
#include "libft.h"
#include "defs.h"

char	*ft_get_env_name(char *eq)
{
	int		i;
	int		size;
	char	*name;

	i = 0;
	size = 0;
	name = NULL;
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
