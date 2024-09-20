#include "../Includes/Timing.h"

void printData(t_timing *time)
{
	system("clear");
	if (time->second >= 0 && time->second <= 9)
	{
		if (time->minute >= 0 && time->minute <= 9)
		{
			if (time->hour >=0 && time->hour <= 9)
				printf(" 0%d:0%d:0%d\n",time->hour,time->minute,time->second);
			else
				printf(" %d:0%d:0%d\n",time->hour,time->minute,time->second);
		}
		else
			printf(" %d:%d:0%d\n",time->hour,time->minute,time->second);
	}
	else if (time->second > 9)
	{
		if  (time->minute > 9)
		{
			printf(" 0%d:%d:%d\n",time->hour,time->minute,time->second);
			if (time->hour > 9)
				printf(" %d:%d:%d\n",time->hour,time->minute,time->second);
		}
		else if (time->minute >= 0 && time->minute <= 9)
		{
			if (time->hour >= 0 && time->hour <= 9)
				printf(" 0%d:0%d:%d\n",time->hour,time->minute,time->second);
			else
				printf(" %d:0%d:%d\n",time->hour,time->minute,time->second);
		}
		else
			printf(" 0%d:0%d:0%d\n",time->hour,time->minute,time->second);
	}
}

int Counter(t_timing *time)
{
	while(1)
	{
		if(time->minute > 59)
		{
			time->minute = 0;
			++time->hour;
		}
		if(time->second > 59)
		{
			time->second = 0;
			++time->minute;
		}
		printData(time);
		sleep(1);
		time->second += 1;
	}
}

int	Timer(t_timing *time)
{
	system("clear");
	time->timer = readline("Timer: ");
	char *token;
	token = strtok(time->timer, ":");
	time->hour = atoi(token);
	token = strtok(NULL, ":");
	time->minute = atoi(token);
	token = strtok(NULL, ":");
	time->second = atoi(token);
	printf(" %d:%d:%d\n",time->hour,time->minute,time->second);
	while (1)
	{
		if (time->second == 0)
		{
			if (time->minute != 0)
			{
				time->second = 59;
				--time->minute;
			}
		}
		if (time->minute == 0)
		{
			if (time->hour != 0)
			{
				time->minute = 59;
				--time->hour;
			}
				
		}
		printData(time);
		if (time->hour == 0 && time->minute == 0 && time->second == 0)
			break;
		else
		{
			sleep(1);
			time->second -= 1;
		}
	}
	return (0);
}

void	init(t_timing *time)
{
	time->option = NULL;
	time->timer= NULL;
	time->hour = 0;
	time->minute = 0;
	time->second = 0;
}

int	main(int argc, char **argv)
{
	t_timing time;
	
	(void)argc;
	(void)argv;

	init(&time);
	while (1)
	{
		system("clear");
		time.option = readline("Options: ");
		if (strcmp(time.option, "Timer") == 0)
			Timer(&time);
		else if (strcmp(time.option, "Counter") == 0)
			Counter(&time);
		else if (strcmp(time.option, "Exit") == 0)
			break;
	}
	free(time.option);
	return (0);
}