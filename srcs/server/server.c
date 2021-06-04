/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:11:45 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 19:17:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

void    signum_action(int signum)
{
    if (signum != SIGUSR1)
    {
        printf("Error signal");
        exit(1);
    }
    if (signum != SIGUSR2)
    {
        printf("Error signal");
        exit(1);
    }
}

int main()
{
    if (signal(SIGUSR1, signum_action))
    {
        write(1, "Error signal 1\n", 14);
    }
    if (signal(SIGUSR2, signum_action))
    {
        write(1, "Error signal 2\n", 14);
    }
    printf("Server pid: %d\n", getpid());
    while (1)
    {}
}
