/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:11:45 by user42            #+#    #+#             */
/*   Updated: 2021/06/07 17:11:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void	write_binary(int signum)
{
	static char	c;
	static int	i;

	if (i == 0)
		i = 8;
	if (signum == SIGUSR1)
		c = c | (0 << --i);
	else if (signum == SIGUSR2)
		c = c | (1 << --i);
	if (i == 0)
	{
		printf("%d\n", c);
		write(1, &c, 1);
		i = 0;
		c = 0;
	}
}

void	signum_action(int signum)
{
	if (signum == SIGUSR1 || signum == SIGUSR2)
		write_binary(signum);
	else
		error(ERRSIGNAL3, NULL);
}

int	main(void)
{
	if (signal(SIGUSR1, signum_action) == SIG_ERR)
		error(ERRSIGNAL2, NULL);
	if (signal(SIGUSR2, signum_action) == SIG_ERR)
		error(ERRSIGNAL2, NULL);
	printf("Server pid: %d\n", getpid());
	while (1)
		pause();
}
