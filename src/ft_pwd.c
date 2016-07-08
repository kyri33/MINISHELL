#include <unistd.h>
#include <stdlib.h>
#include "libft.h"
#include "defs.h"

void	ft_pwd(void)
{
	char	buf[MAX_PATH_SIZE];

	if (getcwd(buf, MAX_PATH_SIZE) == NULL)
		ft_error("Unable to return current working directory.", NULL);
	else
		ft_putendl(buf);
}
