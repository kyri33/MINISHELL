#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "defs.h"

void	ft_env(void)
{
	int			i;
	extern char	**environ;

	i = 0;
	while (environ[i] != NULL)
	{
		ft_putendl(environ[i]);
		i++;
	}
}
