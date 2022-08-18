/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_server.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mthiry <mthiry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 11:34:51 by mthiry            #+#    #+#             */
/*   Updated: 2022/03/24 18:59:56 by mthiry           ###   ########.fr       */
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
	static int				bit = 1;
	static unsigned char	val = 0;
	static int				pid = 0;

	(void)context;
	usleep(100);
	if (info->si_pid != 0)
		pid = info->si_pid;
	if (sig == SIGUSR1)
		val += bit;
	bit <<= 1;
	if (bit == 256)
	{
		bit = 1;
		if (val == 0)
			if (kill(pid, SIGUSR2) == -1)
				error("[ERROR]:\n CAN'T SEND SIGNAL!");
		ft_printf("%c", val);
		val = 0;
	}
	if (kill(pid, SIGUSR1) == -1)
		error("[ERROR]:\n CAN'T SEND SIGNAL!");
}

int	main(void)
{
	struct sigaction	sa;

	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = &signal_handler;
	ft_printf("PID SERVER: %d\n", getpid());
	if (sigaction(SIGUSR1, &sa, NULL) == -1
		|| sigaction(SIGUSR2, &sa, NULL) == -1)
		error("[ERROR]:\n BAD SIGACTION!");
	while (1)
		pause();
	return (0);
}
