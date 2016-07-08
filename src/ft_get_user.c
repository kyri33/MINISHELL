#include <unistd.h>
#include "libft.h"
#include "defs.h"

const char	*ft_get_user()
{
	int			i;
	extern char	**environ;
	char		*user;

	i = 0;
	while (environ[i] != NULL)
	{
		if (ft_strnequ(environ[i], "USERNAME=", 9) == TRUE)
			break ;
		i++;
	}
	user = ft_strchr(environ[i], '=');
	if (user == NULL)
		return (NULL);
	return (user + 1);
}
