#include <stdlib.h>
#include "libft.h"
#include "defs.h"

void	ft_error(char *err, char *err_info)
{
	if (err_info == NULL)
		ft_putendl_fd(err, STDERR);
	else
	{
		ft_putstr_fd(err, STDERR);
		ft_putstr_fd(": ", STDERR);
		ft_putendl_fd(err_info, STDERR);
	}
}
