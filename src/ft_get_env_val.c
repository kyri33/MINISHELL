#include <stdlib.h>
#include "libft.h"
#include "defs.h"

char	*ft_get_env_val(char *eq)
{
	int		i;
	int		size;
	char	*val;

	i = 0;
	size = 0;
	val = NULL;
	eq++;
	while (eq[size] != ' ' && eq[size] != '\t' && eq[size] != '\0')
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
