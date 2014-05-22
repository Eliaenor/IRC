
#include "bircd.h"
#include <stdio.h>
#include <stdlib.h>

int	main(int ac, char **av)
{
	t_env	e;

	init_env(&e);
	if (ac != 2)
	{
		fprintf(stderr, USAGE, av[0]);
		return(1);
	}
	e.port = atoi(av[1]);
	srv_create(&e, e.port);
	main_loop(&e);
	return (0);
}
