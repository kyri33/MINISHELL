/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   defs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khamusek <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/07/08 13:38:26 by khamusek          #+#    #+#             */
/*   Updated: 2016/08/22 16:55:45 by khamusek         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DEFS_H
# define DEFS_H

# include <stdlib.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>
# include <termcap.h>
# include <term.h>
# include <curses.h>
# include "libft.h"

# define MAX_PATH_SIZE 4096
# define CGRN "\x1B[32m"
# define CRED "\x1B[31m"
# define CYEL "\x1B[33m"
# define CMAG "\x1B[35m"
# define CCYN "\x1B[36m"
# define CNRM "\x1B[0m"
# define CBLUE "\x1B[34m"
# define CWHITE "\x1B[37m"

const char	*ft_get_user();
void		ft_exit(char **cmd, int status, char *err);
void		ft_parse_command(char ***cmds);
void		ft_echo(char **cmd);
t_bool		ft_fill_args(char *cmd, char ***argv);
void		ft_del_args(char ***argv);
void		ft_cd(char **cmd);
void		ft_error(char *err, char *err_info);
void		ft_setenv(char **cmd);
void		ft_env(void);
void		ft_pwd(void);
void		ft_unsetenv(char **cmd);
void		ft_execute(char **cmd);
t_bool		ft_rem_spaces(char **cmd);
char		*ft_get_env(char *var);
char		*ft_get_env_name(char *eq);
char		*ft_get_env_val(char *eq);
char		*ft_strjoin_path(char *path, char *cmd);
t_bool		ft_setenv_check_vars(char ***vars);
int			ft_setenv_set_var(char *name, char *val, char **env);
t_bool		ft_term_init(char **term_name, struct termios *term);

#endif
