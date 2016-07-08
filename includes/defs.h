#ifndef DEFS_H
# define DEFS_H

#include "libft.h"

const char	*ft_get_user();
void		ft_exit(char **cmd, int status, char *err);
void		ft_parse_command(char **cmd);
void		ft_echo(char **cmd);
t_bool		ft_fill_args(char **cmd, char ***argv, char *exec_name);
void		ft_del_args(char ***argv);
void		ft_cd(char **cmd);
void		ft_error(char *err, char *err_info);
void		ft_setenv(char **cmd);

#endif
