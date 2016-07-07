#ifndef DEFS_H
# define DEFS_H

#include "libft.h"

const char	*ft_get_user();
void		ft_exit(char **cmd, int status, char *err);
void		ft_parse_command(char **cmd);
void		ft_echo(char **cmd);

#endif
