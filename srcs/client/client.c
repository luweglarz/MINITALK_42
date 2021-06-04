/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/01 22:11:42 by user42            #+#    #+#             */
/*   Updated: 2021/06/04 19:21:30 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/minitalk.h"

int main(int ac, char **av)
{
    if (ac == 3)
    {
        pid_t   serverpid;
        char    *binary;
        int     i;

        serverpid = ft_atoi(av[1]);
        binary = str_to_binary(av[2]);
        i = 0;
        int ret =0;
        printf("%s\n", binary);
        while (binary[i])
        {
            if (binary[i] == '0')
                if ((serverpid, SIGUSR1) == -1)
                {
                    ft_putstr_fd(1, "Failed to send the signal");
                    exit(-1);
                }
            printf("ret 1 %d\n", ret);
            if (binary[i] == '1')
                if ((serverpid, SIGUSR1) == -1)
                {
                    ft_putstr_fd(1, "Failed to send the signal");
                    exit(-1);
                }
                printf("ret 2 %d\n", ret);
            i++;
        }

    }
    else
    {
        ft_putstr_fd(1, "First parameter must be a server PID");
        ft_putstr_fd(1, "Seconde parameter must be the message you want to send to the server");
    }
}