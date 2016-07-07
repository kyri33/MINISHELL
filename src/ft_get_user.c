#include <unistd.h>
#include "libft.h"
#include "defs.h"

const char	*ft_get_user()
{
	extern char	**environ;
	char		*user;

	user = ft_strchr(environ[17], '=');
	return (user + 1);
}
