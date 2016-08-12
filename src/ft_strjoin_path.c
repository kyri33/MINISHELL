#include <stdlib.h>
#include "libft.h"
#include "defs.h"

char	*ft_strjoin_path(char *path, char *cmd)
{
	char	*tmp;
	char	*ret;

	ret = NULL;
	if ((tmp = ft_strjoin(path, "/")) == NULL)
		return (NULL);
	ret = ft_strjoin(tmp, cmd);
	free(tmp);
	return (ret);
}
