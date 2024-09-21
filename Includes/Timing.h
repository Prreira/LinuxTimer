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
	int hourt;
	int	minute;
	int minutet;
	int second;
	int secondt;
}	t_timing;

#endif