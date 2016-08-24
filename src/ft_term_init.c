#include "defs.h"

t_bool	ft_term_init(char **term_name, struct termios *term)
{
	if (((*term_name) = getenv("TERM")) == NULL)
		return (FALSE);
	if (tgetent(NULL, *term_name) == -1)
		return (FALSE);
	if (tcgetattr(0, term) == -1)
		return (FALSE);
	term->c_lflag &= ~(ICANON);
	term->c_lflag &= ~(ECHO);
	term->c_cc[VMIN] = 1;
	term->c_cc[VTIME] = 0;
	if (tcsetattr(0, TCSADRAIN, term) == -1)
		return (FALSE);
	return (TRUE);
}
