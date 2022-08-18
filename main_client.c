/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_client.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:35:22 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/24 19:02:21 by mthiry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/minitalk.h"

static void	error(char *message)
{
	ft_printf("%s\n", message);
	exit (EXIT_FAILURE);
}

static void	signal_handler(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)info;
	(void)context;
}

static void	send_char(pid_t pid, char c)
{
	struct sigaction	sa;
	int					mask;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	mask = 1;
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error("[ERROR]:\n SIGNAL NOT RECEIVED!");
	while (mask <= 128)
	{
		if (c & mask)
		{
			if (kill(pid, SIGUSR1) == -1)
				error("[ERROR]:\n BAD PID!");
		}
		else
		{
			if (kill(pid, SIGUSR2) == -1)
				error("[ERROR]:\n BAD PID!");
		}
		mask <<= 1;
		pause();
	}
}

static void	send_str(pid_t pid, char *str)
{
	int	i;

	i = 0;
	while (str && str[i])
		send_char (pid, str[i++]);
}

int	main(int argc, char **argv)
{
	if (argc != 3)
		error("[ERROR]:\n Use format: ./client <pid> <str>");
	send_str(ft_atoi(argv[1]), argv[2]);
	return (0);
}
