
#include "bircd.h"
#include <stdlib.h>
#include <string.h>
#include <sys/select.h>

void	main_loop(t_env *e)
{
  while (1)
    {
      init_fd(e);
      e->r = select(e->max + 1, &e->fd_read, &e->fd_write, NULL, NULL);
      check_fd(e);
    }
}

void    check_fd(t_env *e)
{
	int   i;

	i = 0;
	while ((i < e->maxfd) && (e->r > 0))
	{
		if (FD_ISSET(i, &e->fd_read))
			e->fds[i].fct_read(e, i);
		if (FD_ISSET(i, &e->fd_write))
			e->fds[i].fct_write(e, i);
		if (FD_ISSET(i, &e->fd_read) ||
				FD_ISSET(i, &e->fd_write))
			e->r--;
		i++;
	}
}

void    init_fd(t_env *e)
{
	int   i;

	i = 0;
	e->max = 0;
	FD_ZERO(&e->fd_read);
	FD_ZERO(&e->fd_write);
	while (i < e->maxfd)
	{
		if (e->fds[i].type != FD_FREE)
		{
			FD_SET(i, &e->fd_read);
			if (strlen(e->fds[i].buf_write) > 0)
			{
				FD_SET(i, &e->fd_write);
			}
			e->max = MAX(e->max, i);
		}
		i++;
	}
}
