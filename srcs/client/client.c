/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:11:42 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 17:06:10 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	send_signals(char *binary, pid_t server_pid)
{
	int		i;

	i = 0;
	while (binary[i])
	{
		if (binary[i] == '0')
		{
			if (kill(server_pid, SIGUSR1) == -1)
				error(ERRSIGNAL1, binary);
		}
		if (binary[i] == '1')
		{
			if (kill(server_pid, SIGUSR2) == -1)
				error(ERRSIGNAL1, binary);
		}
		i++;
	}
	free(binary);
}

int	main(int ac, char **av)
{
	pid_t	server_pid;
	char	*binary;

	if (ac == 3)
	{
		server_pid = ft_atoi(av[1]);
		binary = str_to_binary(av[2]);
		send_signals(binary, server_pid);
	}
	else
	{
		printf("First parameter must be a server PID");
		printf("Second parameter must be the message you want to send");
	}
}
