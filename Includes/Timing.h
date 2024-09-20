#ifndef TIMING_H
# define TIMING_H

#include <stdio.h>
#include <string.h>
#include <readline/readline.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_timing{
	char *option;
	char *timer;
	int hour;
	int	minute;
	int second;
}	t_timing;

#endif